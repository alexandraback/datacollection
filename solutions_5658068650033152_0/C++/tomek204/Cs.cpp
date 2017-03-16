#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MX = 22;

int n, m, k, bitmask, w, t;
bool marked[MX][MX], v[MX][MX];

bool ins(int x, int y) {
	return x >= 0 && y >= 0 && x < m && y < n;
}

void dfs(int a, int b) {
	if (marked[a][b]) return;
	v[a][b] = true;
	t++;
	for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) if (i * j == 0) {
		int A = a + i, B = b + j;
		if (ins(A, B) && !v[A][B]) dfs(A, B);
	}
}

bool check() {
	//printf("Checking %d\n", bitmask);
	int h = __builtin_popcount(bitmask);
	t = 0;
	for (int i = 0; i < n*m; i++) {
		marked[i/n][i%n] = (bitmask&(1<<i)) > 0;
		v[i/n][i%n] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!v[0][i]) dfs(0, i);
		if (!v[m-1][i]) dfs(m-1, i);
	}
	for (int j = 0; j < m; j++) {
		if (!v[j][0]) dfs(j, 0);
		if (!v[j][n-1]) dfs(j, n-1);
	}
	return n * m - t >= k;
}

void solve(int testcase) {
	scanf("%d%d%d", &n, &m, &k);
	w = 100000;
	for (bitmask = 0; bitmask <= (1<<(n*m+1)); bitmask++) if (__builtin_popcount(bitmask) < w && check()) {
		w = __builtin_popcount(bitmask);
	}
	printf("Case #%d: %d\n", testcase, w);
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}