#include <cstdio>
#include <cstring>

double p[110000];

void work()
{
	int T,A,B;
	int cas;
	int i;
	double re;
	double cur, right;
	
	scanf("%d",&T);
	
	for (cas=1;cas<=T;cas++)
	{
		scanf("%d%d",&A,&B);
		for (i=0;i<A;i++)
		{
			scanf("%lf",&p[i]);			
		}
		
		re = 2+B;
		cur = 0;
		right = 1;
		for (i=0;i<A;i++)
		{
			right*=p[i];
			cur=right*(A-i-1+B-i-1+1) + (1-right)*(A-i-1+B-i-1+1+B+1);
			if (cur < re)
				re = cur;
		}
		printf("Case #%d: %.8lf\n",cas,re);
	
	}
}

int main()
{
	//int i;
	
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	work();

	
	return 0;
}
