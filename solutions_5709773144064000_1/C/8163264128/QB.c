#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	int T, x, k, i;
	double C, F, X, A, y;
	scanf("%d ", &T);
	A = 2;
	for (x = 1; x <= T; x++)
	{
		scanf("%lf %lf %lf ", &C, &F, &X);
		k = (int)ceil(X / C - A / F) - 1;
		if (k <= 0) y = X / A;
		else
		{
			y = 0;
			for (i = k - 1; i >= 0; i--)
				y += C / (A + i * F);
			y += X / (A + k * F);
		}
		printf("Case #%d: %.7lf\n", x, y);
	}
	return 0;
}