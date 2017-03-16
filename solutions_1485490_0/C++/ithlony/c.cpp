#include <iostream>
using namespace std;

const int maxn = 110;

int n, a[maxn], m, b[maxn];
long long ac[maxn], bc[maxn], ans;

void dfs(int x, int y, long long g) {
	if (x == n + 1 || y == m + 1) {
		ans = max(ans, g);
	} else {
		if (a[x] == b[y]) {
			int xx = x, yy = y;
			long long t = min(ac[x], bc[y]);
			if (ac[x] <= bc[y]) ++xx;
			if (bc[y] <= ac[x]) ++yy;
			ac[x] -= t;
			bc[y] -= t;
			dfs(xx, yy, g + t); 
			ac[x] += t;
			bc[y] += t;
		} else {
			dfs(x + 1, y, g);
			int i = y;
			while (i <= m && b[i] != a[x]) ++i;
			dfs(x, i, g);
		}

	}
}

int main() {
	int ncase;
	cin >> ncase;
	for (int c = 1; c <= ncase; ++c) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) cin >> ac[i] >> a[i];
		for (int i = 1; i <= m; ++i) cin >> bc[i] >> b[i];
		ans = 0;
		dfs(1, 1, 0);
		cout << "Case #" << c << ": " << ans << endl;
	}
	return 0;
}
