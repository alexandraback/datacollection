#include <stdio.h>

int K, C, S;

void solve() {
	if (C * S < K) {
		puts(" IMPOSSIBLE");
		return;
	}
	for (int _l = 0; _l < K; _l += C) {
		int now = _l;
		long long x = 0;
		for (int j = 0; j < C; j++) {
			x = x * K + now;
			if (now + 1 < K) ++now;
		}
		printf(" %lld", x + 1);
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d:", i);
		solve();
	}
}