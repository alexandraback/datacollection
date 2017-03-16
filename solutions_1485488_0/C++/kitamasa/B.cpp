#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

const int INF = 1000000000;

struct st {
	int x, y, d;
	st():x(0), y(0), d(0){};
	st(int x, int y, int d): x(x), y(y), d(d) {}
	int operator < (const st& s) const {
		if(d != s.d) return d > s.d;
		return make_pair(x, y) > make_pair(s.x, s.y);
	}
};

int fl[110][110], ce[110][110];
int d[110][110];
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

void go(int h, int n, int m, bool b) {
	priority_queue<st> que;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(d[i][j] == 0) que.push(st(i, j, 0));
		}
	}
	while(que.size()) {
		st s = que.top(); que.pop();
		if(s.d > d[s.x][s.y]) continue;
		// cerr << s.x << " " << s.y << " " << s.d << endl;
		// if(s.x == n - 1 && s.y == m - 1) break;
		for(int i = 0; i < 4; ++i) {
			int x = s.x + dx[i], y = s.y + dy[i];
			if(x < 0 || y < 0 || x >= n || y >= m) continue;
			if(ce[x][y] - fl[x][y] < 50 || ce[x][y] - fl[s.x][s.y] < 50 || ce[s.x][s.y] - fl[x][y] < 50) continue;
			int nd = s.d + max(0, (h - s.d) - (ce[x][y] - 50));
			if(!b && nd > 0) continue;
			if(h - nd >= 20 + fl[s.x][s.y]) nd += 10;
			else nd += 100;
			if(!b) nd = 0;
			// cerr << "h " << x << " " << y << " " << nd << endl;
			if(d[x][y] <= nd) continue;
			d[x][y] = nd;
			que.push(st(x, y, d[x][y]));
		}
	}
}

int main() {
	int T;
	cin >> T;
	for(int c = 1; c <= T; ++c) {
		printf("Case #%d: ", c);
		int h, n, m;
		cin >> h >> n >> m;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> ce[i][j];
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin >> fl[i][j];
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				d[i][j] = INF;
			}
		}
		d[0][0] = 0;
		go(h, n, m, false);
		go(h, n, m, true);
		printf("%.5f\n", d[n - 1][m - 1] / 10.0);
	}
	return 0;
}
