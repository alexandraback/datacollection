#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1005], c[1005], g[1005];
int n, ans = 0;
void dfs(int k, int d) {
	if (g[f[k]]) {
		ans = max(ans, d - g[f[k]] + 1);
		if (g[f[k]] == d - 1) {
			ans = max(ans, d);
			for (int i = 1; i <= n; ++i) {
				if (!g[i]) {
					c[d] = k, g[k] = d;
					dfs(i, d + 1);
					c[d] = g[k] = 0;
				}
			}
		}
		return;
	}
	c[d] = k, g[k] = d;
	dfs(f[k], d + 1);
	c[d] = g[k] = 0;
}
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", f + i + 1);
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		c[1] = i, g[i] = 1;
		dfs(f[i], 2);
		c[1] = g[i] = 0;
	}
	printf("%d\n", ans);;
}
int main() {
	//freopen("in", "r", stdin);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}
