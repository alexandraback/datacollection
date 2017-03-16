#include <stdio.h>

int main() {
	int T;
	freopen("x.txt", "r", stdin); freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);
		int ans = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((i & j) < K) {
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}
