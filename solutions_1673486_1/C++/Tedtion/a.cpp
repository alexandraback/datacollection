#include <stdio.h>
#define NN 100000

double p[NN];

double min_ep(int a, int b)
{
	double minep, ep, rp;
	int i;
	minep = b+2;
	rp = 1.0;
	for (i=1; i<=a; i++)
	{
		rp *= p[i-1];
		ep = rp*(a-i + b-i+1) + (1-rp)*(a-i + b-i+1 + b+1);
		if (ep < minep) minep = ep;
	}
	return minep;
}

int main()
{
	int	t,a,b,i;
	freopen("a-large.in", "r", stdin);
	freopen("a-large.out", "w", stdout);
	scanf("%d",&t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d%d",&a,&b);
		for (i=0; i<a; i++) scanf("%lf",&p[i]);
		printf("Case #%d: %.7lf\n", cas, min_ep(a,b));
	}
	return 0;
}

