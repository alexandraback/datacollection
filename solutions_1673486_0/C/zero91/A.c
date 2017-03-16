#include <stdio.h>
#include <string.h>

#define MAX 100001
#define INF 999999999

int
main (void)
{
	int i, j, T, A, B;
	double P[MAX];
	double right[MAX];
	double min, sum;

	scanf ("%d", &T);
	for (j = 1; j <= T; ++j) {
		scanf ("%d%d", &A, &B);
		right[0] = 1.0;
		for (i = 1; i <= A; ++i) {
			scanf ("%lf", P + i);
			right[i] = right[i - 1] * P[i];
		}
		min = right[A] * (B - A + 1) + (1 - right[A]) * (B * 2 - A + 2);

		if (min > B + 2) {
			min = B + 2;
		}
		sum = 0.0;
		for (i = 1; i <= A; ++i) {
			sum = right[A - i] * (B - A + 2 * i + 1) + (1 - right[A - i]) * (B * 2 - A + 2 * i + 2);
			if (sum < min) {
				min = sum;
			}
		}
		if (sum < min) {
			min = sum;
		}
		printf ("Case #%d: %.6f\n", j, min);
	}
	return 0;
}

