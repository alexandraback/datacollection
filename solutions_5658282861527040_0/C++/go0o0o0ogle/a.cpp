#include <stdio.h>

int A, B, K;

int calc()
{
	int ret = 0;
	int i, j;
	for (i = 0; i < A; i++) {
		for (j = 0; j < B; j++) {
			int t = i & j;
			if (t < K) {
				ret++;
			}
		}
	}
	return ret;
}

int main()
{
	int cs, k;
	scanf("%d", &cs);
	for (k = 0; k < cs; k++) {
		scanf("%d%d%d", &A, &B, &K);
		printf("Case #%d: %d\n", k + 1, calc());
	}
	return 0;
}