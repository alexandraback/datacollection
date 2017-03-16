#include <stdio.h>

double MIN(double a,double b)
{
	if(a<b)
		return a;
	return b;
}

int main()
{
	int i,j,T,A,B;
	double p,min,P[99999];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d",&A,&B);
		p=1.0;
		for(j=0;j<A;j++)
		{
			scanf("%lf",&P[j]);
			p*=P[j];
		}
		min=1.0*B+2;
		for(j=0;j<=A;j++)
		{
			if(j!=0)
				p/=P[A-j];
			min=MIN(min,(B-A+1+2*j)+(1-p)*(B+1));
		}
		printf("Case #%d: %.6lf\n",i+1,min);
	}
	return 0;
}
