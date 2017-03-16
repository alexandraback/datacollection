// Michał Łazowik

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <utility>

using namespace std;

typedef long long LL;

#define REP(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, b, e) for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) for (int x = b; x >= (e); --x)
#define FOREACH(it, cont) for (__typeof(cont.begin()) it = cont.begin(); it != cont.end(); ++it)

#define F first
#define S second
#define MP make_pair
#define PB push_back

const int BARZYLION = 2e9;
const int MAX = 30;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

struct Trial {
	int n, m;
	bool grid[MAX][MAX];
	bool vis[MAX][MAX];

	int ind(int x, int y) {
		return y * m + x;
	}

	Trial(int n, int m, int mask) {
		this->n = n;
		this->m = m;

		FOR(i, 0, m+1) {
			grid[i][0] = true;
			grid[i][n+1] = true;
		}
		FOR(i, 0, n+1) {
			grid[0][i] = true;
			grid[m+1][i] = true;
		}
		
		FOR(i, 1, n) FOR(j, 1, m) {
			vis[j][i] = false;
			grid[j][i] = ((mask & (1<<ind(j-1, i-1))) != 0);
		}
	}

	void dfs(int x, int y) {
		vis[x][y] = true;

		REP(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!vis[nx][ny] && !grid[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}

	int getRes() {
		int res = 0;

		FOR(i, 1, n) {
			if (!grid[1][i]) dfs(1, i);
			if (!grid[m][i]) dfs(m, i);

		}
		FOR(i, 1, m) {
			if (!grid[i][1]) dfs(i, 1);
			if (!grid[i][n]) dfs(i, n);
		}

		FOR(i, 1, n) FOR(j, 1, m) {
			if (!vis[j][i]) res++;
		}

		return res;
	}

	void print() {
		FOR(i, 1, n) {
			FOR(j, 1, m) {
				printf("%d ", grid[j][i]);
			}
			printf("\n");
		}
	}
};

int solve(int n, int m, int k) {
	int res = BARZYLION;
	Trial *t;

	int pot = 1;
	REP(i, n*m) {
		pot *= 2;
	}

	REP(mask, pot) if (__builtin_popcount((unsigned int)mask) < res) {
		t = new Trial(n, m, mask);
		if (t->getRes() >= k) {
			res = __builtin_popcount((unsigned int)mask);
		}

		delete[] t;
	}

	return res;
}

int main() {
	int t, n, m, k;

	scanf("%d", &t);

	FOR(q, 1, t) {
		scanf("%d %d %d", &n, &m, &k);
		printf("Case #%d: ", q);
		printf("%d", solve(n, m, k));
		printf("\n");
	}

	return 0;
}
