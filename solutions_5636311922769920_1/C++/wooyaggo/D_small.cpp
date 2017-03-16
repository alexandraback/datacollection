#include <stdio.h>

int K, C, S;

int main(void) {
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		scanf("%d %d %d", &K, &C, &S);
		if (S < (K + (C-1))/C) {
			printf("IMPOSSIBLE\n");
			continue;
		} else if(K == 1) {
			printf("1\n");
			continue;
		}
		long long idx = 0;
		for (int i = 0; i < K; i++) {
			idx = idx * (long long)K + (long long)i;
			if (i == K-1 || i % C == C-1) {
				printf("%I64d ", idx + 1);
				idx = 0;
			}
		}
		printf("\n");
	}
	return 0;
}