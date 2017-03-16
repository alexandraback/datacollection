#include <stdio.h>
#include <stdlib.h>

#define MAX_E 6
#define MAX_R 6
#define MAX_N 11
#define MAX_V 11

int T;
long long int E,R,N;
long long int a[MAX_N];
long long int best;

void rec(long long int n, long long int e,long long int g){
	long long int i;
	if(n==N){
		if(g>best) best=g;	
		return;
	}
	if(e>E)e=E;
	for(i=0;i<=e;i++){
		rec(n+1,e-i+R,g+(a[n]*i));
	}
}

int main(void){
	int i,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		best=0;
		scanf("%lld %lld %lld",&E,&R,&N);
		for(i=0;i<N;i++){
			scanf("%lld",&a[i]);
		}
		rec(0,E,0);
		printf("Case #%d: %lld\n",t,best);

	}
	return 0;
}
