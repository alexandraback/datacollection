#include<stdio.h>

unsigned int count_small(unsigned int A, unsigned int B, unsigned int K)
{
	unsigned int res=0;
	for(unsigned int i=0; i<A; i++)
	{
		for(unsigned int j=0;j<B;j++)
		{
			unsigned lot = i&j;
			if(lot<K)
				res++;
		}
	}
	return res;
}

void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	unsigned A,B,K;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%u %u %u",&A,&B,&K);
		printf("Case #%d: %u\n", cs, count_small(A,B,K));
	}
}