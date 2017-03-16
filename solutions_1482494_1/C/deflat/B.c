/**************************
*   Google Code Jam 2012  *
*        Round 1A         *
*        Problem B        *
*                         *
 *************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
#define LP(i,a,b) for(i=a;i<b;i++)
#define RANGEQ(a,b,c) (a<=b && b<=c)

int a[MAX],b[MAX];
int comp(int x,int y){
	if(b[x]>b[y]) return 1;
	else return 0;
}

int main(){
	FILE *fp1,*fp2;
	char filename[50];
	int i,j,T,n,ans,stars,candidate,flag;
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");

	fp2=fopen("output.txt","w");
	
	fscanf(fp1,"%d",&T);
	LP(i,0,T){
		fscanf(fp1,"%d",&n);
		LP(j,0,n) fscanf(fp1,"%d %d",&a[j],&b[j]);
		stars=0,ans=0;
		while(stars<2*n){
			candidate=-1,flag=0;
			LP(j,0,n){
				if(RANGEQ(0,b[j],stars)){
					if(a[j]!=-1){
						a[j]=-1,b[j]=-1;
						stars+=2;
						break;
					}else{
						candidate=j;
						flag=1;
					}
				}else if(RANGEQ(0,a[j],stars)){
					if(flag==0&&(candidate==-1||comp(j,candidate))){
						candidate=j;
					}
				}
			}
			if(j==n){
				if(candidate==-1){
					ans=-1;
					break;
				}else{
					stars++;
					if(flag==1){
						b[candidate]=-1;
					}else{
						a[candidate]=-1;
					}
				}
			}
			ans++;
		}
		
		if(ans!=-1){
			fprintf(fp2,"Case #%d: %d\n",i+1,ans);
		}else{
			fprintf(fp2,"Case #%d: Too Bad\n",i+1);
		}
	}
	return 0;
}