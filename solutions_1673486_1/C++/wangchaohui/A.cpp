#include <stdio.h>

double p[100010];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,C=0;
	scanf("%d",&T);
	while(++C<=T)
	{
		printf("Case #%d: ",C);
		int A,B;
		scanf("%d %d",&A,&B);
		int i;
		double x=1;
		double m=B+2;
		for(i=0;i<A;i++)
		{
			scanf("%lf",&p[i]);
			x*=p[i];
			double t=B-i+(1-x)*(B+1)+A-1-i;
			if(t<m)m=t;
		}
		printf("%.10f\n",m);
	}
	return 0;
}
