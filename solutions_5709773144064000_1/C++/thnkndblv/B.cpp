using namespace std;

#include "bits/stdc++.h"

int main()
{
	int ntc;

	scanf("%d", &ntc);
	for (int tc = 1; tc <= ntc; tc++)
	{
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);

		double ans = X / 2.0;

		double tm = 0.0;
		double prod = 2.0;
		for (int i = 1; i <= ceil( X ); i++)
		{
			tm += C / prod;
			prod += F;

			ans = min( ans, tm + X / prod );
		}

		printf("Case #%d: %.7lf\n", tc, ans);
	}

	return 0;
}
