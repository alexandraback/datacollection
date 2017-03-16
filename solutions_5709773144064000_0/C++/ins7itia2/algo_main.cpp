#include <cstdio>
#include <algorithm>
#include <vector>

double compute(double C, double F, double X)
{
	int n = 0;
	double time = 0.;
	while(1)
	{
		double left = X / (F*(double)(n)+2.);
		double right = C / (F*(double)(n)+2.);

		if(left < (right + X / (F*(double)(n + 1) + 2.)))
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
		double C;
		double F;
		double X;

		scanf("%lf", &C);
		scanf("%lf", &F);
		scanf("%lf", &X);

		double ret = compute(C, F, X);

		printf("Case #%d: %lf\n", numCase, ret);

		++numCase;
	}

	return 0;
}