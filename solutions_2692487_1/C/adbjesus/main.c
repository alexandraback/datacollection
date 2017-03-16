#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int T,N;
long long A;
long long a[MAX];
long long best;

int cmp(const void *a,const void *b){
	if((*(long long *)a)<(*(long long *)b)) return -1;
	return 1;
}

void rec(int n,long long c){
	if(c>=best) return;
	if(n==N){
		if(c<best) best=c;
		return;
	}
	if(a[n]<A){
		A+=a[n];
		rec(n+1,c);
		A-=a[n];
	}
	else{
		if(A!=1){
			A=A+A-1;
			rec(n,c+1);
			A=(A+1)/2;
		}
		if(c+N-n<best) best=c+N-n;
	}
	
}

int main(void){
	int i,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		best=1<<30;
		scanf("%lld %d",&A,&N);
		for(i=0;i<N;i++){
			scanf("%lld",&a[i]);
		}
		qsort(a,N,sizeof(long long),cmp);
		rec(0,0);
		printf("Case #%d: %lld\n",t,best);	
	}

	return 0;
}

