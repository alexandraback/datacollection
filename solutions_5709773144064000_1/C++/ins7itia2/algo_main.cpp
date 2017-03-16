#include <cstdio>
#include <algorithm>
#include <vector>

 long double compute(long double C, long double F, long double X)
{
	int n = 0;
	long double time = 0.;
	while(1)
	{
		long double left = X / (F*(long double)(n)+2.);
		long double right = C / (F*(long double)(n)+2.);

		if(left < (right + X / (F*(long double)(n + 1) + 2.)))
		{
			time += left;
			break;
		}

		time += right;
		++n;
	}

	return time;
}

int main(int argc, char **argv)
{
	int T;
	scanf("%d", &T);
	int numCase = 1;
	while(T-- > 0)
	{
		long double C;
		long double F;
		long double X;

		scanf("%lf", &C);
		scanf("%lf", &F);
		scanf("%lf", &X);

		long double ret = compute(C, F, X);

		printf("Case #%d: %lf\n", numCase, ret);

		++numCase;
	}

	return 0;
}