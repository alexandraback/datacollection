#include<cstdio>
using namespace std;

double minx(double a, double b)
{
	if(a < b)
		return a;
	return b;
}

int main()
{
	int t,a,b;
	double p[100010],ans,allp,pnow[100010];
	scanf("%d",&t);

	for(int cases=1; cases<=t; cases++)
	{
		scanf("%d%d",&a,&b);
		pnow[0] = allp = 1.0;
		for(int i=1; i<=a; i++)
		{
			scanf("%lf",&p[i]);
			allp *= p[i];
			pnow[i] = pnow[i-1]*p[i];
		}

		ans = 0;
		ans = minx(b+2, allp*(b-a+1) + (1-allp)*(2*b-a+2));
		for(int k=1; k<a; k++)
		{
			ans = minx(ans, pnow[a-k]*(2*k+b-a+1) + (1-pnow[a-k])*(2*k+2*b-a+2));
		}
		ans = minx(ans, a+b+1); 

		printf("Case #%d: %lf\n",cases,ans);
	}
	return 0;
}
