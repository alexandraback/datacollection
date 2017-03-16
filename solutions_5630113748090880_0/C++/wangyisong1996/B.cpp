#include <stdio.h>
#include <string.h>
#include <assert.h>

const int MAXN = 2505;

bool cnt[MAXN];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	int n;
	scanf("%d", &n);
	int i, j;
	for (i = 1; i < 2 * n; i++) {
		for (j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			cnt[x] ^= 1;
		}
	}
	static int ans[55];
	int t = 0;
	for (i = 1; i < MAXN; i++) {
		if (cnt[i]) {
			ans[++t] = i;
		}
	}
	assert(t == n);
	for (i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i < n ? ' ' : '\n');
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}