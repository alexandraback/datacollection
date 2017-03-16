#include <string>
#include <set>
#include <ctime>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define INF 1000000000

int n, m, k, ans, cnt = 0;
bool d[55][55];
pair<int, int> o[55];
bool q[55][55];

bool ch(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < m && q[x][y] && !d[x][y]) return true;
	return false;
}

int count() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			d[i][j] = false;
	int yk1 = 0, yk2 = 0;
	for (int i = 0; i < n; ++i) {
		if (q[i][0]) {
			o[yk1++] = make_pair(i, 0);
			d[i][0] = true;
		}
		if (q[i][m-1]) {
			d[i][m-1] = true;
			o[yk1++] = make_pair(i, m - 1);
		}
	}
	for (int i = 1; i < m - 1; ++i) {
		if (q[0][i]) {
			d[0][i] = true;
			o[yk1++] = make_pair(0, i);
		}
		if (q[n-1][i]) {
			d[n-1][i] = true;
			o[yk1++] = make_pair(n-1,i);
		}
	}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	while (yk1 > yk2) {
		pair<int, int> q = o[yk2++];
		int x = q.first, y = q.second;
		for (int i = 0; i < 4; ++i) {
			int xx, yy;
			xx = x + dx[i];
			yy = y + dy[i];
			if (ch(xx, yy)) {
				d[xx][yy] = true;
				o[yk1++] = make_pair(xx, yy);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!d[i][j]) ret++;
	return ret;
}

void rec(int x, int y) {
	if (x == n) {
		int e = count();
		if (e >= k) {
			ans = cnt;
		}
		return;
	}
	if (ans <= cnt) return;
	q[x][y] = 0;
	cnt++;
	if (y == m - 1) rec(x + 1, 0); else rec(x, y + 1);
	cnt--;
	q[x][y] = 1;
	if (y == m - 1) rec(x + 1, 0); else rec(x, y + 1);
	q[x][y] = 0;
}

void solve() {
	cin >> n >> m >> k;
	ans = 10000;
	cnt = 0;
	rec(0, 0);
	cout << ans << endl;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int tests = 1; tests <= t; ++tests) {
		cout << "Case #" << tests << ": ";
		solve();
	}
	return 0;
}



