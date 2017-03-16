#include <cstdio>

int b[20][20];

void color(const int x, const int y, const int n, const int m) {
	if (x < 0 || x >= n || y < 0 || y >= m || b[x][y] != 0) return;
	b[x][y] = 2;
	color(x - 1, y, n, m);
	color(x + 1, y, n, m);
	color(x, y - 1, n, m);
	color(x, y + 1, n, m);
}

bool check(const int a[20], const int n, const int m, const int k) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			b[i][j] = a[i * m + j];
	}
	for (int i = 0; i < m; ++i) {
		color(0, i, n, m);
		color(n - 1, i, n, m);
	}
	for (int i = 0; i < n; ++i) {
		color(i, 0, n, m);
		color(i, m - 1, n, m);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (b[i][j] == 2)
				++cnt;
	return (n * m - cnt == k);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int ans = k;
		int tmp = (1 << (n * m));
		while (tmp > 0) {
			--tmp;	
			int cnt = 0, a[20] = {0}, i = 0, t = tmp;
			while (t) {
				if (t & 1) {
					a[i] = 1;
					++cnt;
				}
				t = (t >> 1);
				++i;
			}
			if (cnt < ans && check(a, n, m, k)) ans = cnt;
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}
