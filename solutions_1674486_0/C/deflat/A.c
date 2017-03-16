/**************************
*   Google Code Jam 2012  *
*        Round 1C         *
*        Problem A        *
 *************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
#define LP(i,a,b) for(i=a;i<b;i++)
#define RANGE(a,b,c) (a<=b&&b<=c)

int inherit[MAX][MAX];
int inherit2[MAX][10];
int m[MAX],n;
int counter[MAX];


int check(int x){	
	int i,ans=0,flag=0;

	LP(i,0,n){
		if(inherit[x][i]==1){

			flag=1;
			if(counter[i]==1) return 1;
			else counter[i]=1;
		}
	}
	if(flag==0) return 0;
	else{
		for(i=0;i<m[x]&&ans==0;i++){
			ans=check(inherit2[x][i]);
		}
		return ans;
	}
}

int main(){
	FILE *fp1,*fp2;
	char filename[50];
	int i,j,k,T,ans,target;
	double p;
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	fp2=fopen("output.txt","w");
	
	fscanf(fp1,"%d",&T);
	LP(i,0,T){
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf(fp1,"%d",&n);
		
		LP(j,0,n){
		LP(k,0,n){
		inherit[j][k]=0;
		}}
		
		LP(j,0,n){
			fscanf(fp1,"%d",&m[j]);
			LP(k,0,m[j]){
				fscanf(fp1,"%d",&target);
				inherit[j][target-1]=1;
				inherit2[j][k]=target-1;
			}
		}
		ans=0;
		for(j=0;j<n&&ans==0;j++){
			LP(k,0,n) counter[k]=0;
			ans=check(j);
		}
		if(ans==1) fprintf(fp2,"Yes\n");
		else fprintf(fp2,"No\n");
	}
	return 0;
}