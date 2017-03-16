#include <stdio.h>

#define MAX 200

int
main (void)
{
	int T, N;
	int i, j, sum;
	int other[MAX], score[MAX];
	double p;

	scanf ("%d", &T);
	for (i = 1; i <= T; ++i) {
		scanf ("%d", &N);
		sum = 0;
		for (j = 0; j < N; ++j) {
			scanf ("%d", score + j);
			sum += score[j];
		}
		for (j = 0; j < N; ++j) {
			other[j] = sum - score[j];
		}
		printf ("Case #%d: ", i);
		for (j = 0; j < N; ++j) {
			p = (double)(other[j] + sum - (N - 1) * score[j]) * 100.0 / (sum * N);
			if (p < 0) p = 0.0;
			printf ("%f", p);
			if (j < N - 1) putchar (' ');
		}
		printf ("\n");
	}

	return 0;
}
