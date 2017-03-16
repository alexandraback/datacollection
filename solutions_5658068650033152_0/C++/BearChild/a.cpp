#include <cstdio>
#include <cstring>

const int N = 105;
const int INF = 0x3f3f3f3f;
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, k, ans, v[N][N];

bool cat (int x, int y) {

	for (int i = 0; i < 4; i++) {
		int p = x + d[i][0];
		int q = y + d[i][1];

		if (p < 0 || p >= n)
			return false;
		if (q < 0 || q >= m)
			return false;

		if (v[p][q] == 0)
			return false;
	}
	return true;
}

void judge () {

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (v[i][j] && cat(i, j)) {
				cnt++;
			}
		}
	}

	if (cnt > ans)
		ans = cnt;
}

void dfs (int x, int y, int c) {

	if (c == k) {
		judge();
		return;
	}

	if (y == m) {
		y = 0;
		x++;
	}
	
	if (x >= n)
		return;

	v[x][y] = 0;
	dfs (x, y + 1, c);
	v[x][y] = 1;
	dfs (x, y + 1, c + 1);
	v[x][y] = 0;
}

int main () {
	int cas;
	scanf("%d", &cas);

	for (int i = 1; i <= cas; i++) {
		ans = 0;
		scanf("%d%d%d", &n, &m, &k);
		dfs(0, 0, 0);
		printf("Case #%d: %d\n", i, k - ans);
	}
	return 0;
}
