#include <stdio.h>
#include <stdlib.h>

int R;
int N,M,K;

int P[20];
int p;
int F[12];

int rec(int n,int r){
	int i,j;
	if(n==N){
		if(r==1) return 1;
		return 0;
	}
	for(i=2;i<=M;i++){
		if(r%i==0){
			j=rec(n+1,r/i);
			if(j==1){
				F[n]=i;
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	int i,tmp,j,k;
	printf("Case #1:\n");
	scanf("%*d %d %d %d %d",&R,&N,&M,&K);
	p=0;
	for(i=0;i<R;i++){
		for(j=0;j<N;j++) F[j]=2;
		for(j=0,k=0;j<K;j++){
			scanf("%d",&tmp);
			if(tmp!=1 && k==0){
				k=rec(0,tmp);
			}
		}
		for(j=0;j<N;j++){
			printf("%d",F[j]);
		}	
		printf("\n");
	}
	return 0;	

}
