#include <stdio.h>

#define maxb (100005)

int T;
int A, B;

double pp[maxb];

double min2d(double a, double b)
{
	return (a <= b) ? a : b;
}

int main()
{
	int tt;
	scanf("%d", &T);

	for(tt = 1; tt <= T; ++tt)
	{
		int i, j;

		pp[0] = 1;

		scanf("%d %d", &A, &B);
		for(i = 1; i <= A; ++i)
		{
			double p;
			scanf("%lf", &p);

			pp[i] = pp[i - 1] * p;

//			printf("%d : %lf\n", i, pp[i]);
		}

		double sol = B + 2;

		for(i = 0; i <= A; ++i)
		{
			sol = min2d(sol, B - A + 1 + 2 * i + (1 - pp[A - i]) * (B + 1));
		}

		printf("Case #%d: %.6lf\n", tt, sol);
	}

	return 0;
}
