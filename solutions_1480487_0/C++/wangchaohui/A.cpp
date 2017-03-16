#include <stdio.h>
#define eps 1e-10

int d[200];
int N,S;

int check(int i,double y)
{
	int j;
	double s=d[i]+S*y;
	y=1-y;
	for(j=0;j<N;j++)
	{
		if(i==j)continue;
		if(d[j]<s+eps)
		{
			double t=(s-d[j])/S;
			if(t>y+eps)
			{
				return 1;
			}
			y-=t;
		}
	}
	return 0;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,TC=0;
	scanf("%d",&T);
	while(++TC<=T)
	{
		printf("Case #%d:",TC);
		int i,j;
		scanf("%d",&N);
		S=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&d[i]);
			S+=d[i];
		}
		for(i=0;i<N;i++)
		{
			double hi=1,lo=0;
			for(j=0;j<200;j++)
			{
				double mi=(hi+lo)/2;
				if(check(i,mi))
				{
					hi=mi;
				}
				else
				{
					lo=mi;
				}
			}
			printf(" %.8f",hi*100);
		}
		putchar('\n');
	}
	return 0;
}
