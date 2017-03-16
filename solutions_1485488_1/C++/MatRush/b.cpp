#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 111;
int f[MAXN][MAXN], c[MAXN][MAXN];
int n, m, h;
struct data {
	int i, j;
	double t;
} e, t;
bool operator <(const data& a, const data& b) {
	return a.t > b.t;
}
bool mat[MAXN][MAXN];
priority_queue<data> q;
int fx[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int notvalid(int i, int j) {
	return i < 0 || j < 0 || i >= n || j >= m || f[i][j] - c[i][j] < 50;
}
double gao() {
	memset(mat, 0, sizeof(mat));
	while (!q.empty())q.pop();
	e.i = e.j = e.t = 0;
	q.push(e);
	while (q.size()) {
		e = q.top();
		q.pop();
		if (mat[e.i][e.j]++) continue;
		if (e.i == n - 1 && e.j == m - 1) return e.t;
		for (int z = 0; z < 4; z++) {
			t.i = e.i + fx[z][0];
			t.j = e.j + fx[z][1];
			if (notvalid(t.i, t.j)) continue;
			int mn = min(f[e.i][e.j], f[t.i][t.j]);
			int mx = max(c[e.i][e.j], c[t.i][t.j]);
			if (mn - mx < 50) continue;
			double ts = max(((h - (mn - 50)) / 10.0), e.t);
			if (ts == 0) {
				t.t = 0;
			} else if (h - ts*10 < c[e.i][e.j] + 20) {
				t.t = ts + 10;
			} else {
				t.t = ts + 1;
			}
			q.push(t);
		}
	}
	return -1;
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T = 0, cas;
	scanf("%d", &cas);
	while (cas--) {
		cin >> h >> n >> m;
		for (int i = 0; i < n; i++)
			for (int q = 0; q < m; q++)
				cin >> f[i][q];
		for (int i = 0; i < n; i++)
			for (int q = 0; q < m; q++)
				cin >> c[i][q];
		printf("Case #%d: %.1lf\n", ++T, gao());
	}
	return 0;
}

