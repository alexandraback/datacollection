/**************************
*   Google Code Jam 2012  *
*        Round 1B         *
*        Problem A        *
*                         *
 *************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 500
#define LP(i,a,b) for(i=a;i<b;i++)
#define RANGE(a,b,c) (a<=b&&b<=c)
#define CI(c) (c-'0');
int main(){
	FILE *fp1,*fp2;
	char filename[50];
	int i,j,k,T,n,s[MAX],x,n2,x2;
	double ans,checker,target;
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	fp2=fopen("output.txt","w");
	
	fscanf(fp1,"%d",&T);
	LP(i,0,T){
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf(fp1,"%d",&n);
		x=0;
		LP(j,0,n){
			fscanf(fp1,"%d",&s[j]);
			x+=s[j];
		}
		n2=n,x2=x;
		LP(j,0,n){
			if(s[j]*n>=x*2){
				n2--,x2-=s[j],s[j]=-1;
				}
		}
		target=(double)(x+x2)/(double)n2;
		LP(j,0,n){
		if(s[j]==-1) ans=0.0;
		else ans=100.0*(target-(double)s[j])/(double)x;
		fprintf(fp2,"%.6lf ",ans);
		}
		fprintf(fp2,"\n");
	}
	return 0;
}