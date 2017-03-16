#include "cstdio"

int main()
{
	int T;
	double cps,C,F,X,ans;
	scanf("%d",&T);
	for (int Case = 1; Case <= T; Case++)
	{
		ans = 0;
		cps = 2;
		scanf("%lf %lf %lf",&C, &F, &X);
		while(true)
		{
			if (X/cps < (C/cps + X/(cps+F)))
			{
				ans += X/cps;
				printf("Case #%d: %.7lf\n", Case, ans);
				break;
			}
			else
			{
				ans += C/cps;
				cps += F;
			}
		}
	}
	return 0;
}