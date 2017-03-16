#include <stdio.h>

void solve(int t, int A, int B, int K)
{
	int acc = 0, i, j;
	for (i = 0; i < A; ++i) {
		for (j = 0; j < B; ++j) {
			if ((i & j) < K) ++acc;
		}
	}
	printf("Case #%d: %d\n", t, acc);
}

int main()
{
	int T, i;

	scanf("%d", &T);
	for (i = 1; i <= T; ++i) {
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);
		solve(i, A, B, K);
	}
	return 0;
}
