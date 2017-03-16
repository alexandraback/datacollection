/**************************
*   Google Code Jam 2012  *
*        Round 1A         *
*        Problem A        *
*    for Small & Large    *
 *************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 99999
#define LP(i,a,b) for(i=a;i<b;i++)

float comp(float a,float b){
	if(a<b) return a;
	else return b;
}

int main(){
	FILE *fp1,*fp2;
	char filename[50];
	int i,j,k,T,BS;
	float ans,temp,p2;
	int A,B;
	float p;
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	fp2=fopen("output.txt","w");
	
	fscanf(fp1,"%d",&T);
	LP(i,0,T){
		p2=1.0;
		fscanf(fp1,"%d %d",&A,&B);
		ans=B+2.0;
		LP(j,0,A){
			fscanf(fp1,"%f",&p);
			p2*=p;
			BS=A+B-1-2*j;
			temp=p2*BS+(1-p2)*(BS+B+1);
			ans=comp(ans,temp);
		}
		fprintf(fp2,"Case #%d: %f\n",i+1,ans);
	}
	return 0;
}