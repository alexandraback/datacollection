#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

struct node {
	int A, B;
} level[MAX];

int
cmp (const struct node *left, const struct node *right)
{
	if (left->A == right->A)
		return right->B - left->B;
	return left->A - right->A;
}

int
main (void)
{
	int i, j, k, flag1, flag2;
	int T, N, result, score;
	char done[MAX];

	scanf ("%d", &T);
	for (i = 1; i <= T; ++i) {
		scanf ("%d", &N);
		for (j = 0; j < N; ++j) {
			scanf ("%d%d", &level[j].A, &level[j].B);
		}
		qsort (level, N, sizeof (struct node), (int(*)(const void *, const void*))cmp);

		memset (done, 0, sizeof (done));

		score = result = 0;
		k = 0, flag1 = 1;

		while (1) {
			flag2 = 1;
			while (flag2) {
				flag2 = 0;
				for (j = 0; j < N; ++j) {
					if (done[j] == 2) continue;
					if (done[j] == 1) {
						if (score >= level[j].B) {
							++result;
							score += 1;
							done[j] = 2;
							flag2 = 1;
						}
					} else if (score >= level[j].B) {
						++result;
						score += 2;
						done[j] = 2;
						flag2 = 1;
					}
				}
			}

			for (j = 0; j < N; ++j) {
				if (done[j] < 1 && score >= level[j].A) {
					done[j] = 1;
					score += 1;
					++result;
					break;
				}
			}
			if (j >= N) break;
		}

		for (j = 0; j < N; ++j) {
			if (done[j] != 2) {
				break;
			}
		}
		if (j < N) {
			printf ("Case #%d: Too Bad\n", i);
			continue;
		}
		printf ("Case #%d: %d\n", i, result);
	}
	return 0;
}
