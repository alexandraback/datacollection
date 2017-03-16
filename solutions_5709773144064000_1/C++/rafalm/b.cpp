#include <cstdio>

int main()
{
	int T, test;
	double C, F, X, time, prod;

	scanf("%d", &T);
	for (test = 1; test <= T; test++)
	{
		scanf("%lf", &C);
		scanf("%lf", &F);
		scanf("%lf", &X);

		time = 0.0;
		prod = 2.0;
		while ((X / prod) > (C / prod) + (X / (prod + F)))
		{
			time += (C / prod);
			prod += F;
		}

		printf("Case #%d: %.7lf\n", test, time + (X / prod));
	}

	return 0;
}
