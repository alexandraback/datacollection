#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

int main() {

    int T;
    cin>>T;

    int ***A;
    char ***Adir;
    A=(int ***)malloc(502*sizeof(int **));
    Adir=(char ***)malloc(502*sizeof(char **));
    for(int i=0;i<502;i++){
		A[i]=(int **)malloc(402*sizeof(int *));
		Adir[i]=(char **)malloc(402*sizeof(char *));
        for(int j=0;j<402;j++){
			A[i][j]=(int *)malloc(402*sizeof(int));
			Adir[i][j]=(char *)malloc(402*sizeof(char));
		}
	}
    char str[1000];// = (char *)malloc(1000*sizeof(char));
    char str1[1000];//= (char *)malloc(1000*sizeof(char));
    int x,y,j,k,l,loop,newj,newk;
    A[0][100][100]=1;
    for(int i=1;i<=T;i++){
		for(j=0;j<502;j++){
			for(k=0;k<402;k++){
				for(l=0;l<402;l++){
					A[j][k][l]=0;
				}
			}
		}
        A[0][200][200]=1;
        cin>>x;
        cin>>y;
/*        loop=0;
        while(loop<=500){
            loop++;
            for(j=-200;j<=200;j++){
                for(k=-200;k<=200;k++){
                    if(A[loop-1][200+j][200+k]==1){
                            newj=j+loop;
                            newk=k;
                            if(newj>200 || newj<-200 || newk>200 || newk<-200){

                            }
                            else{
                                A[loop][newj+200][newk+200]=1;
                                Adir[loop][newj+200][newk+200]='E';
                            }
                            
                            newj=j-loop;
                            newk=k;
							if(newj>200 || newj<-200 || newk>200 || newk<-200){

                            }
                            else{
                                A[loop][newj+200][newk+200]=1;
                                Adir[loop][newj+200][newk+200]='W';
                            }

							newj=j;
							newk=k+loop;
							if(newj>200 || newj<-200 || newk>200 || newk<-200){

                            }
                            else{
                                A[loop][newj+200][newk+200]=1;
                                Adir[loop][newj+200][newk+200]='N';
                            }

							newj=j;
							newk=k-loop;
							if(newj>200 || newj<-200 || newk>200 || newk<-200){

                            }
                            else{
                                A[loop][newj+200][newk+200]=loop;
                                Adir[loop][newj+200][newk+200]='S';
                            }
                    }
                }
            }

            if(A[loop][x+200][y+200]==1){
                break;
            }
        }

strcpy(str,"");
        for(j=loop;j>=1;j--){
//            str="";
            if(Adir[j][x+200][y+200]=='N'){
                y=y-j;
                strcpy(str1,"N");
                strcat(str1,str);
                strcpy(str,str1);
//                str='N'+str;
            }
            else if(Adir[j][x+200][y+200]=='S'){
                y=y+j;
				strcpy(str1,"S");
                strcat(str1,str);
                strcpy(str,str1);
//                str='S'+str;
            }
            else if(Adir[j][x+200][y+200]=='E'){
                x=x-j;
  				strcpy(str1,"E");
                strcat(str1,str);
                strcpy(str,str1);
//                str='E'+str;
            }
            else if(Adir[j][x+200][y+200]=='W'){
                x=x+j;
				strcpy(str1,"W");
                strcat(str1,str);
                strcpy(str,str1);	
//                str='W'+str;
            }
        }*/
printf("Case #%d: ",i);
		if(x<0){
			x=-x;
			for(j=0;j<x;j++){
				printf("EW");
			}
		}
		else{
			for(j=0;j<x;j++){
				printf("WE");
			}
		}
		if(y<0){
			y=-y;
			for(j=0;j<y;j++){
				printf("NS");
			}
		}
		else{
			for(j=0;j<y;j++){
				printf("SN");
			}
		}
        printf("\n");
    }
							
 


    return 0;
}
