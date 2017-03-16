#include <stdio.h>
#include <string.h>

int main()
{
	int _cn,_cc,i,a,b;
	double q,m,x;
	scanf("%d",&_cn);
	for (_cc=1;_cc<=_cn;++_cc)
	{
		scanf("%d %d",&a,&b);
		q=1.0;
		m=2+b;
		for (i=0;i<=a;++i)
		{
			if (q*(a-i+b-i+1)+(1-q)*(a-i+b-i+1+b+1)<m) m=q*(a-i+b-i+1)+(1-q)*(a-i+b-i+1+b+1);
			if (i<a)
			{
				scanf("%lf",&x);
				q*=x;
			}
		}
		printf("Case #%d: %.10lf\n",_cc,m);
	}
	return 0;
}
