#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define max(X,Y) ((X)>(Y)?(X):(Y))
#define min(X,Y) ((X)<(Y)?(X):(Y))

#define MAXN 100

int intCompare(const void * a, const void * b)
{
	int aa,bb;

	aa = *((int *) a);
	bb = *((int *) b);
	if(aa<bb)
		return -1;
	else if(aa==bb)
		return 0;
	else
		return 1;
}

int main()
{
	int i,res,tcase,T,N,s[MAXN+1],extra[MAXN+1],A;
	long long sum;

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&A);
		scanf("%d",&N);
		res=N;
		for(i=0;i<N;i++)
		{
			scanf("%d",s+i);
			extra[i]=0;
		}
		if(A == 1)
		{
			printf("Case #%d: %d\n",tcase,res);
			continue;
		}

		qsort(s,N,sizeof(int),intCompare);

		sum = A;
		for(i=0;i<N;i++)
		{
			if(s[i] >= sum)
			{
				extra[i] = 1 + log2(s[i]-1) - log2(sum-1);
				sum--;
				sum <<= extra[i];
				sum++;
			}
			sum += s[i];
		}
		for(i=1;i<N;i++)
			extra[i] += extra[i-1];
		for(i=0;i<N;i++)
			res = min(res, extra[i]+N-1-i);

		printf("Case #%d: %d\n",tcase,res);
	}


	return 0;
}
