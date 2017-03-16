#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
int p[N];
int f[N][N];
int dfs(int a, int b) {
	if (~f[a][b]) return f[a][b];
	if (a <= b) return f[a][b] = 0;
	else {
		int ret = 0x3f3f3f3f;
		for (int i = 1; i < a; ++i) {
			ret = min(ret, dfs(i, b) + dfs(a - i, b) + 1);
		}
		return f[a][b] = ret;
	}
}
int main() {
	//freopen("B-small-attempt3.in", "r", stdin);
	//freopen("B-small-ans.txt", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large-ans.txt", "w", stdout);
	memset(f, 0xff, sizeof f);
	int T, ca = 1, n;
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
		}
		sort(p, p + n);
		int ret = 0x3f3f3f3f;
		for (int i = 1; i <= p[n - 1]; ++i) {
			int x = 0;
			for (int j = 0; j < n; ++j) {
				if (p[j] > i) {
					x += dfs(p[j], i);
				}
			}
			ret = min(ret, x + i);
		}
		printf("Case #%d: %d\n", ca++, ret);
	}
	return 0;
}

