#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int z=0,y=0;
int i,n,count=0;                  
void addbooks(int b);
void mainmenu();
void studentmenu();
void deleteindex(int);
void bookdetails();
void bookdetailss();
void deletebooks();
void editbooks();
void viewlist();
void viewlistss();
void reserve_book();
void selectbran();
void searchbook();
//structure for book details.
struct books
{
	char b_name[40];
	int id;
	char author[20];
	int price;
	int qua;
	char file[50];
	char bran;
}s[60];
//structures for subjects.
struct books civil[] =
{
	{"Why Things Don't Fall Down    ",1437,"J.E. Gordon        ",700  ,15  ,"civil.txt"},
	{"The Civil Engineering Handbook",1438,"Wai-Fah Chen       ",600  ,10  ,"civil.txt"},
	{"Circles In the Sky            ",1439,"Ray Roddy          ",400  ,30  ,"civil.txt"},
	{"Civil Engineering Material    ",1440,"Shan Somayaji      ",500  ,15  ,"civil.txt"},
	{"Basic Structural Analysis     ",1441,"C S Reddy          ",600  ,20  ,"civil.txt"},
	{"Surveying                     ",1443,"B.C.Punia          ",600  ,40  ,"civil.txt"},
	{"Building Materials            ",1444,"S.K. Duggal        ",780  ,30  ,"civil.txt"},
	{"The Tower and the Bridge      ",1445,"David P. Billington",800  ,40  ,"civil.txt"},
	{"Structural Analysis & Design  ",1446,"Janak P. Parikh    ",700  ,25  ,"civil.txt"},
};
struct books electrical[] =
{
	{"Basic Electrical Engineering         ",1401,"Nagsarkar          ",500,35,"electrical.txt"},
	{"Circuit Theory                       ",1402,"A. ChakrabartiRai  ",459,35,"electrical.txt"},
	{"Electrical Machines-I                ",1403,"B.L.Theraja        ",999,35,"electrical.txt"},
	{"Industrial Electronics               ",1404,"G.K. Mittal        ",689,35,"electrical.txt"},	
	{"Network Theory                       ",1405,"B.N.Yoganarasimha  ",499,35,"electrical.txt"},
	{"Analog Electronics                   ",1406,"A. Rajkumar        ",799,35,"electrical.txt"},
	{"Digital Communication                ",1407,"DR. J.S.CHITODE    ",570,35,"electrical.txt"},
	{"Fundamentals of Electrical Engineering",1408,"Rajendra Prasad    ",699,35,"electrical.txt"},
	{"Electronics & Communication           ",1409,"M.PRESH NAVE       ",999,35,"electrical.txt"},
	{"Electronics and Communication        ",1410,"Prem R Chadha      ",899,35,"electrical.txt"},
};
struct books mech[] =
{
	{"Fluid Mechanics and Hydraulic Machines",1456,"Dr. R K Bansal     ",500,20,"mechanical.txt"},
	{"Machine Design                        ",1457,"R S Khurmi         ",455,56,"mechanical.txt"},
	{"Theory of Machines                    ",1458,"J.K.Gupta          ",377,35,"mechanical.txt"},
	{"Theory of Machines                    ",1459,"SS Rattan          ",200,45,"mechanical.txt"},	 
	{"Mechanical Vibrations                 ",1460,"G K Grover         ",400,34,"mechanical.txt"},									 
	{"Basic & Applied Thermodynamics        ",1461,"P K Nag            ",255,49,"mechanical.txt"},
	{"Engineering Mechanics                 ",1462,"S S Bhavikatti     ",450,20,"mechanical.txt"},
	{"Design of Machine Elements            ",1463,"V B Bhandari       ",299,15,"mechanical.txt"},
	{"Fluid Mechanics                       ",1464,"Huebsch & Rothmayer",300,45,"mechanical.txt"},		
	{"Introduction to Mechanics             ",1465,"Robert Kolenkow    ",399,30,"mechanical.txt"},	
};
struct books cse[] =
{
    {"Computer Fundamentals                  ",1414,"Reema Thareja       ",495,10,"cse.txt"},
    {"Fundamentals of CSE                    ",1415,"A.P.Godse           ",225,20,"cse.txt"},
    {"Computer Networks                      ",1416,"I.A.Dhotre V.S.Bagad",299,12,"cse.txt"},
    {"Object-Oriented Analysis               ",1417,"Siddharth Santosh   ",270,13,"cse.txt"},
    {"Parallel Computing                     ",1418,"M. Bader            ",400,25,"cse.txt"},
    {"The Network Designer                   ",1419,"A.M. Jones          ",245,19,"cse.txt"},
    {"Parallel Programming and Applications  ",1420,"Peter A. Fritzson   ",950,22,"cse.txt"},
    {"Formal Methods and Software Development",1421,"Maurice Nivat       ",546,22,"cse.txt"},
    {"Concurrent Systems Engineering Series  ",1422,"T. Dayar            ",580,19,"cse.txt"},
    {"Computer Graphics                      ",1111,"S.Sharanya          ",1423,8,"cse.txt"},
};

void studentmenu()
{
	printf("\t\t\t\t****************HOME*****************\n");
	int f;
	printf("\t\t\t\t1.View book details\n\t\t\t\t2.View book list\n\t\t\t\t3.searchbook\n\t\t\t\t4.Reserve\n\t\t\t\t5.exit\n\t\t\t\t******************************************************\n");
	printf("\t\t\t\tEnter your choice:");
	scanf("%d",&f);	
		switch(f)
	{
		case 1:bookdetailss();
		break;
		case 2:viewlistss();
		break;
		case 3:searchbook();
		break;
		case 4: reserve_book();
		break;
		default:printf("\t\t\t\tInvalid input");
	}
}
void viewlistss()
{
	printf("\t\t\t\t**************VIEW LIST************\n");
	int i,k=3,j,l,m,ch;
	char c;
	FILE *fp1,*fp2,*fp3,*fp4;
	printf("\t\t\t\tSelect branch\n");
	printf("\t\t\t\t1.Computer science\n\t\t\t\t2.Electricals\n\t\t\t\t3.Mechanical\n\t\t\t\t4.Civil\n\t\t\t\t5.main menu");
	scanf("\n\t\t\t\t%d\n",&ch);
	switch(ch)
	{
		case 1:printf("\n\t\t\t\tComputer science\n");
				for(i=0;i<10;i++)
				{
					int s;
					printf("\n\t\t\t\t%s                      %d     %s                   %d    %d   ",cse[i].b_name,cse[i].id,cse[i].author,cse[i].price,cse[i].qua);
					fp1 = fopen(cse[i].file,"r");
					fscanf(fp1,"%d",&s);
					fclose(fp1);
				}
						break;
		case 2:printf("Electrical\n");
					for(i=0;i<10;i++)
					{
						int g;
				printf("\n\t\t\t\t%s                            %d      %s                 %d  %d",electrical[i].b_name,electrical[i].id,electrical[i].author,electrical[i].price,electrical[i].qua);
						fp2 = fopen(electrical[i].file,"r");
					fscanf(fp2,"%d",&g);
					fclose(fp2);
					}
				break;
		case 3:printf("Mechanical\n");
					for(i=0;i<10;i++)
			{
				int o;
				printf("\n\t\t\t\t%s                             %d       %s                   %d  %d",mech[i].b_name,mech[i].id,mech[i].author,mech[i].price,mech[i].qua);
						fp3 = fopen(mech[i].file,"r");
					fscanf(fp3,"%d",&o);
					fclose(fp3);
			}	
			break; 
		case 4:printf("\t\t\t\tCivil\n");
					for(i=0;i<10;i++)
			{
				int a;
				printf("\n\t\t\t\t%s                                 %d       %s               %d   %d",civil[i].b_name,civil[i].id,civil[i].author,civil[i].price,civil[i].qua);
 				fp4 = fopen(civil[i].file,"r");
				fscanf(fp4,"%d",&a);
				fclose(fp4);
			}
		break;
		case 5: studentmenu();
		break;
	}		
	switch(s[i].bran)
		{
			
			case 1:printf("Computer science\n");
			break;
			case 2:printf("Electrical\n");
			break;
			case 3:printf("Mechanical\n");
			break;
			case 4:printf("Civil\n");
			break;
		}
		k++;
	printf("\t**************************************************************************************************\n");
	printf("\t\tDo you want to go to Main menu(Y/N):");
	fflush(stdin);
	scanf("\t\t\t\t%c",&c);
	if(c=='y'||c=='Y')
	{
		studentmenu();
	}
