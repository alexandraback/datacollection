#include <stdio.h>

#define min(a,b) ((a) < (b) ? (a) : (b))

int
main (void)
{
	int T, N, S, P, score;
	int i, j, large, mid;

	scanf ("%d", &T);
	for (i = 1; i <= T; ++i) {
		large = mid = 0;
		scanf ("%d%d%d", &N, &S, &P);
		for (j = 0; j < N; ++j) {
			scanf ("%d", &score);
			if (score >= 3*P - 2) {
				++large;
			} else if (score >= 3*P - 4 && 3*P >= 4) {
				++mid;
			}
		}
		printf ("Case #%d: %d\n", i, large + min (S, mid));
	}

	return 0;
}
