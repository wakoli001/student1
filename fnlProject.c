#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct  student{
         int age, Id;
	     char name[50];
	     float marks;
   };

void addStudent(){
   	   FILE  *fp;
   	   struct student s;
 			fp = fopen("student.txt","w");

	if(fp == NULL){
		printf("Error Openning the file!!\n ");
        fclose(fp);
     }
printf("      Enter Details :");
fgets(s.name, sizeof(s.name), stdin);
printf("\n        Enter your name : ");
fgets(s.name, sizeof(s.name), stdin);
printf("       Enter your Id :");
scanf("%d", &s.Id);
printf("        Enter Your age :");
scanf("%d", &s.age);
printf("        Enter your Marks :");
scanf("%.2f", &s.marks);
printf("");
scanf("%f",&s.marks);
fwrite(&s, sizeof(s), 1, fp);
fprintf(fp,"%d",s.Id);
fprintf(fp, "%d", s.age);
fprintf(fp,"%f", s.marks);
fprintf(fp,"%s", s.name);



fclose(fp);

}
void displayStudent(){
       FILE *fp;
	struct student s;
	fp = fopen("student.txt","r");
 	if(fp ==NULL){
		printf("No records found!!\n");
	return;
		}
	printf("\n----------STUDENT DATA------------\n");
        while(fread(&s, sizeof(s), 1,  fp)){
	printf("Student Id : %d\n",s.Id);
	printf("Age : %d\n",s.age);
	printf("Marks : %f\n",s.marks);
	printf("Name : %s\n",s.name);
      }
fclose(fp);
}

void searchStudent(){
FILE *fp;
struct student s;
int searchId, found =0;
   fp = fopen("student.txt","r");
	if(fp==NULL){
          printf("File Not Found!!\n");
	}
printf("Enter student Id to search : ");
scanf("%d", &searchId);
   while(fread(&s, sizeof(s), 1, fp)){
		if(searchId == s.Id){
		  printf("---student Found---\n");
		  printf("Name : %s\n",s.name);
		  printf("Student Id : %d\n", s.Id);
		  printf("Student Age : %d\n", s.age);
		  printf("Student Marks : %f\n", s.marks);
          printf("\n--x--x--x--x--x--x--x--x--x--x-x--\n");

         found =1;
           break;
      }
}
if(!found){
	printf("No student Record with Id Found!!\n");
 }
fclose(fp);
}

int main(){
      int choice;
      FILE *fp;
      fp = fopen("student.txt","a");
      struct student s;
while(1){
	printf("\n=====================================\n");
	printf("--------STUDENT RECORD SYSTEM--------\n");
	printf("           1. Add Student   \n");
	printf("           2. Display Student   \n");
	printf("           3. Search Student    \n");
	printf("           4. Exit    \n");
	printf("Enter your Choice : ");
    scanf("%d", &choice);
printf("\n---o-o-o-o-o-o-o-o-o--o-o-o-o-o-o-o-o-o-o-o-o--o-o-o-o-o-o-o-o-o-o-o---\n");
switch(choice){
	  case 1:
		addStudent();
	break;

	case 2:
		displayStudent();
	break;

	case 3:
		searchStudent();
	break;

	case 4:
		printf("Exiting The system ---\n");
        exit(1);
	break;

	default:
		printf("Invalid Choice , Please Try Again Later\n");
    }
}
return 0;
}
