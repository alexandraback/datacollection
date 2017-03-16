#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	if (*(double*)a - *(double*)b > 1e-6) {
		return 1;
	}
	else 
		return 0;
}

int main() {
	int T, N, i, j, k;
	double block[2][1005];
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		for (j = 0; j < 2; j++) {
			for (k = 0; k < N; k++)
				scanf("%lf", &block[j][k]);
		}
		qsort(block[0], N, sizeof(double), cmp);
		qsort(block[1], N, sizeof(double), cmp);
		/*
		for (j = 0; j < 2; j++) {
			for (k = 0; k < N; k++)
				printf("%lf ", block[j][k]);
			printf("\n");
		}
		*/
		printf("Case #%d: ", i + 1);
		j = k = 0;
		while (j < N) {
			if (block[0][j] - block[1][k] > 1e-6) {
				j++;
				k++;
			}
			else
				j++;
		}
		printf("%d ", k);
		j = N - 1, k = N - 1;		
		while (j >= 0) {
			if (block[0][j] - block[1][k] > 1e-6)
				j--;
			else {
				k--;
				j--;
			}
		}
		printf("%d\n", k + 1);
	}
	return 0;
}
