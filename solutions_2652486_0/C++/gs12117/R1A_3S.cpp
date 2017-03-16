#include<stdio.h>
int t,r,n,m,p;
int prod[20];
int nump[20];
int pnt;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,l;
	printf("Case #1:\n");
	scanf("%d%d%d%d%d",&t,&r,&n,&m,&p);
	for(i=0;i<r;i++){
		for(j=0;j<15;j++)nump[j]=0;
		for(j=0;j<p;j++){
			scanf("%d",&prod[j]);
			for(k=2;k<15;k++){
				l=0;
				while(prod[j]%k==0){
					l++;
					prod[j]/=k;
				}
				if(nump[k]<l)nump[k]=l;
			}
		}
		for(j=0;j<nump[5];j++)printf("5");
		for(j=0;j<nump[3];j++)printf("3");
		pnt=n-nump[3]-nump[5];
		for(j=0;j<pnt;j++){
			if((pnt-j)*2>nump[2]){
				printf("2");
				nump[2]--;
			}
			else{
				printf("4");
				nump[2]-=2;
			}
		}
		printf("\n");
	}
}