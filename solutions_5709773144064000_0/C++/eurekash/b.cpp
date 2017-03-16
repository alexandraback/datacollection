#include <cstdio>
#include <cstring>

int main()
{
	int t,tt;
	double c,f,x;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		double a=2.0,ans=0.0;
		while((x-c)/a>x/(a+f))  ans+=c/a, a+=f;
		ans+=x/a;
		printf("Case #%d: %.7f\n",tt,ans);
	}
	return 0;
}
