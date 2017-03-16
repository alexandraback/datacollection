#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <numeric>
#include <utility>
#include <functional>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

double ans;

int c[128][128], f[128][128], v[128][128];
int h, n, m;

bool check(int si, int sj, int ti, int tj, double h, double &ts, bool &drop)
{
	if (c[ti][tj] - f[ti][tj] < 50) return false;
	if (c[ti][tj] - f[si][sj] < 50) return false;
	if (c[si][sj] - f[ti][tj] < 50) return false;
	double d = 50.0 - ((double) c[ti][tj] - h);
	if (d > 0) drop = true;
	ts = max(0.0, d) / 10.0;
	h = max(0.0, h - ts * 10.0);
	if ((h - f[si][sj]) >= 20.0) ts += 1.0;
	else ts += 10.0;
	return true;
}

void dfs(int i, int j, double t, double h, bool drop)
{
	if (i == n - 1 && j == m - 1) {
		ans = min(t, ans);
		return;
	}
	
	v[i][j] = 1;

	double ts;
	if (i > 0 && v[i - 1][j] == 0 && t <= ans) {
		bool start_drop = drop;
		if (check(i, j, i - 1, j, h, ts, start_drop)) {
			if (start_drop)
				dfs(i - 1, j, t + ts, max(0.0, h - ts * 10.0), start_drop);
			else
				dfs(i - 1, j, t, h, start_drop);
		}
	}

	if (i < n - 1 && v[i + 1][j] == 0 && t <= ans) {
		bool start_drop = drop;
		if (check(i, j, i + 1, j, h, ts, start_drop)) {
			if (start_drop)
				dfs(i + 1, j, t + ts, max(0.0, h - ts * 10.0), start_drop);
			else
				dfs(i + 1, j, t, h, start_drop);
		}
	}

	if (j > 0 && v[i][j - 1] == 0 && t <= ans) {
		bool start_drop = drop;
		if (check(i, j, i, j - 1, h, ts, start_drop)) {
			if (start_drop)
				dfs(i, j - 1, t + ts, max(0.0, h - ts * 10.0), start_drop);
			else
				dfs(i, j - 1, t, h, start_drop);
		}
	}
	
	if (j < m - 1 && v[i][j + 1] == 0 && t <= ans) {
		bool start_drop = drop;
		if (check(i, j, i, j + 1, h, ts, start_drop)) {
			if (start_drop)
				dfs(i, j + 1, t + ts, max(0.0, h - ts * 10.0), start_drop);
			else
				dfs(i, j + 1, t, h, start_drop);
		}
	}

	v[i][j] = 0;
}

int main(int argc, char *argv[])
{
	int nc;
	scanf("%d", &nc);
	for (int ci = 1; ci <= nc; ci++) {
		scanf("%d %d %d", &h, &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) scanf("%d", &c[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) scanf("%d", &f[i][j]);
		memset(v, 0, sizeof(v));
		ans = 1e10;
		dfs(0, 0, 0.0, (double) h, false);
		printf("Case #%d: %f\n", ci, ans);
	}

	return 0;
}
