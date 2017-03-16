#include <stdio.h>
#define eps 1e-13

int check(int N,int S[],int sum,int j,double mid)
{
	int i;
	double score=S[j]+sum*mid;
	double remain=1-mid;
	for(i=0;i<N;i++)
		if(i!=j&&score>S[i])
			remain-=(double)(score-S[i])/sum;
	return (remain>0);
}

int main()
{
	int i,j,T,N,S[200],sum;
	double left,right,mid;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(j=0;j<N;j++)
			scanf("%d",&S[j]);
		sum=0;
		for(j=0;j<N;j++)
			sum+=S[j];
		printf("Case #%d:",i+1);
		for(j=0;j<N;j++)
		{
			left=0.0;
			right=1.0;
			while(right-left>eps)
			{
				mid=(left+right)/2;
				if(check(N,S,sum,j,mid))
					left=mid;
				else
					right=mid;
			}
			printf(" %.6lf",(left+right)/2*100);
		}
		printf("\n");
	}
	return 0;
}

