#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1010
#define min(a, b) (a < b) ? (a) : (b);

int N, P[MAX_N];

int solve();
int compare(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}

int main()
{
	int T, t, i, ans;
	FILE* fp = fopen("B-small.out", "w");

	scanf("%d", &T);
	for(t = 1; t <= T; t++) {
		scanf("%d", &N);
		for(i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}
		ans = solve();
		fprintf(fp, "Case #%d: %d\n", t, ans);
	}
	fclose(fp);
	return 0;
}

int solve() {
	int ret, n, sum, i;

	qsort(P, N, sizeof(int), compare);
	ret = P[0];
	n = 2;
	while(n < ret) {
		sum = 0;
		for(i = 0; i < N; i++) {
			sum += (P[i] - 1) / n;
		}
		ret = min(ret, sum + n);
		n++;
	}
	return ret;
}
