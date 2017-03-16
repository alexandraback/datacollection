#include <stdio.h>
double p[100000];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,z,t,a,b;
	double min,sav,che;
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		min=9999999;
		sav=1;
		printf("Case #%d: ",z);
		scanf("%d",&a);
		scanf("%d",&b);
		for(i=1;i<=a;i++)
		{
			scanf("%lf",&p[i]);
		}
		for(i=1;i<=a;i++)
		{
			sav*=p[i];
			che=sav*(a-i+b-i+1)+(1-sav)*(a+2*b-2*i+2);
			min=min>=che?che:min;
		}
		che=(b+2);
		min=min>=che?che:min;
		printf("%lf\n",min);
	}
	return 0;
}