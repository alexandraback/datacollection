#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000100

int intCmp(const int *a, const int *b){
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	return 0;
}

int T, N;

int sizes[MAXN];

int min(int a, int b){
	return a < b ? a : b;
}

int bs(int acc, int start){
	int limit = N - start;
	int best = limit;
	int i, j;

	for (i = 1; i < limit; i++){
		acc += acc - 1;

		for (; start < N && sizes[start] < acc; start++)
			acc += sizes[start];

		best = min(best, i + (N - start));
	}

	return best;
}

int main(void){
	int t, i, acc;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %d", &acc, &N);

		for (i = 0; i < N; i++)
			scanf("%d", &sizes[i]);

		qsort(sizes, N, sizeof(sizes[0]), intCmp);

		for (i = 0; sizes[i] < acc && i < N; i++)
			acc += sizes[i];

		printf("Case #%d: %d\n", t, bs(acc, i));
	}

	return 0;
}
