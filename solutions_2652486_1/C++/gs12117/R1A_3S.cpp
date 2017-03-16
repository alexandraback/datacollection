#include<stdio.h>
#include<stdlib.h>
int t,r,n,m,p;
int prod[20];
int nump[20];
int need[20];
int pnt;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,l;
	printf("Case #1:\n");
	scanf("%d%d%d%d%d",&t,&r,&n,&m,&p);
	srand(4376);
	for(i=0;i<r;i++){
		for(j=0;j<15;j++){
			nump[j]=0;
			need[j]=0;
		}
		for(j=0;j<p;j++){
			scanf("%d",&prod[j]);
			if(prod[j]%4==2){
				need[2]=1;
			}
			if(prod[j]%6==3){
				need[3]=1;
			}
			if(prod[j]%8==4){
				need[4]=1;
			}
			for(k=2;k<15;k++){
				l=0;
				while(prod[j]%k==0){
					l++;
					prod[j]/=k;
				}
				if(nump[k]<l)nump[k]=l;
			}
		}
		for(j=0;j<nump[7];j++)printf("7");
		for(j=0;j<nump[5];j++)printf("5");
		pnt=n-nump[5]-nump[7];
		if(need[2]){
			printf("2");
			pnt--;
		}
		if(need[3]){
			printf("3");
			pnt--;
		}
		if(need[4]&&(pnt>nump[3]&&!need[2])){
			printf("4");
			pnt--;
		}
		for(j=0;j<pnt;j++){
back:
			if(rand()%8==0){
				if((pnt-1)<(nump[3]-1))goto back;
				printf("8");
				nump[2]-=3;
			}
			else if(rand()%6==0){
				if((pnt-1)*3<(nump[2]-1))goto back;
				printf("6");
				nump[2]-=1;
				nump[3]-=1;
			}
			else if(rand()%4==0){
				if((pnt-nump[3]-1)*3<(nump[2]-nump[3]-2))goto back;
				printf("4");
				nump[2]-=2;
			}
			else if(rand()%4==0||rand()%4==0){
				if((pnt-nump[3])*3<(nump[2]-nump[3]+1))goto back;
				printf("3");
				nump[3]-=1;
			}
			else{
				if((pnt-nump[3]-1)*3<(nump[2]-nump[3]-1))goto back;
				printf("2");
				nump[2]-=1;
			}
			if(nump[2]<0)nump[2]=0;
			if(nump[3]<0)nump[3]=0;
		}
		printf("\n");
	}
}