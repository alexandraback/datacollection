#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

int n, m, sum, T, k, ans;
bool t[20][20], used[20][20];

void dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || used[x][y] || t[x][y])	return ;
	used[x][y] = true;
	sum++;
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int check(int S) {
	memset(t, 0, sizeof t);
	memset(used, 0, sizeof used);
	
	for (int i = 0; i < n * m; i++)
		if (S & (1 << i))	t[i / m][i % m] = true;
	sum = 0;
	for (int i = 0; i < n; i++)
		if (!t[i][0] && !used[i][0])	dfs(i, 0);
	for (int i = 0; i < n; i++)
		if (!t[i][m - 1] && !used[i][m - 1])	dfs(i, m - 1);
	for (int i = 0; i < m; i++)
		if (!t[0][i] && !used[0][i])	dfs(0, i);
	for (int i = 0; i < m; i++)
		if (!t[n - 1][i] && !used[n - 1][i])	dfs(n - 1, i);
	return n * m - sum;
}

int s(int S) {
	int sum = 0;
	for (int i = 0; i < n * m; i++)
		if (S & (1 << i))	sum++;
	return sum;
}

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (int Case = 1; Case <= T; Case++) {
		scanf("%d%d%d", &n, &m, &k);
		ans = 1000;
		for (int i = 0; i < (1 << (n * m)); i++)	if (check(i) >= k)	ans = min(ans, s(i));
		printf("Case #%d: %d\n", Case, ans);
	}
}
