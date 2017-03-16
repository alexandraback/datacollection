#include<stdio.h>
#include<string.h>
#include<iostream>

#define SZ 100005

using namespace std;

double p[SZ];
double pm[SZ];

int main()
{
	int i, j, k, a, b, tot;
	freopen("a-large.in", "rt", stdin);
	freopen("a-large.out", "wt", stdout);

	int inp, kase;
	scanf("%d", &inp);
	//long double pp = 0.1;

	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d %d", &a, &b);
		for(i = 0; i < a; i++)
			scanf("%lf", &p[i]);

		pm[0] = p[0];
		for(i = 1; i < a; i++)
		{
			pm[i] = pm[i - 1] * p[i];
		}
		tot = b + 1;
		double mx = b + 2;
		double ex = 0;
		for(i = 1; i <= a; i++)
		{
			ex = (1.0 - pm[i - 1]) * (tot + 2.0 * (a - i) + (b - a + 1)) + pm[i - 1] * (2.0 * (a - i) + (b - a + 1));
			if(ex < mx)
				mx = ex;
		}
		//if(mx)
		printf("Case #%d: %.9lf\n", kase, mx);
	}
	return 0;
}
