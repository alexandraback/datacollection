#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define max(X,Y) ((X)>(Y)?(X):(Y))
#define min(X,Y) ((X)<(Y)?(X):(Y))

long long gcd(long long a, long long b)
{
	long long t;

	while(b)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int power2(long long Q)
{
	int counter=0,bit;
	while(1)
	{
		bit=Q&1;
		Q = Q>>1;
		if(Q && bit)
			return -1;
		if(!Q)
			return counter;
		counter++;
	}
}

int main()
{
	int tcase,T,res,logQ;
	long long P,Q,d;

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%lld",&P);
		getchar();
		scanf("%lld",&Q);
		d=gcd(P,Q);
		P=P/d;
		Q=Q/d;
		logQ=power2(Q);
		if(logQ<0 || logQ>40)
		{
			printf("Case #%d: impossible\n",tcase);
			continue;
		}
		res = logQ-((int) log2((double) P));
		printf("Case #%d: %d\n",tcase,res);
	}


	return 0;
}

