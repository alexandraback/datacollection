
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 101;
int tests, n, m, a[maxn][maxn], col[maxn], row[maxn];

int main() {
	// freopen("B-large.in", "r", stdin);
	// freopen("B-large.out", "w", stdout);
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		scanf("%d%d", &n, &m);
		memset(col, 0, sizeof(col));
		memset(row, 0, sizeof(row));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &a[i][j]);
				row[i] = max(row[i], a[i][j]);
				col[j] = max(col[j], a[i][j]);
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == row[i] || a[i][j] == col[j]) continue;
				flag = false;
			}
		}
		printf("Case #%d: ", tt);
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
