#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>
#include <set>

#define px first
#define py second
#define mp make_pair

using namespace std;

const double EPS = 1e-10;
const int MAXN = 100;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

typedef pair<double, pair<int, int> > state;

int h, n, m;
int fl[MAXN][MAXN], cl[MAXN][MAXN];

inline bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

inline bool canMove(int x, int y, int nx, int ny) {
	if (cl[nx][ny] - fl[nx][ny] < 50) {
		return false;
	}
	if (cl[nx][ny] - fl[x][y] < 50) {
		return false;
	}
	if (cl[x][y] - fl[nx][ny] < 50) {
		return false;
	}
	return true;
}

void solve() {
	scanf("%d%d%d", &h, &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &cl[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &fl[i][j]);
		}
	}
	set<state> q, used;
	//vector<vector<bool> > used(n, vector<bool>(m, false));
	q.insert(mp(-1, mp(0, 0)));
	while (!q.empty()) {
		state cur = *q.begin();
		q.erase(q.begin());
		used.insert(cur);
		//used[cur.py.px][cur.py.py] = true;
		if (cur.py == mp(n - 1, m - 1)) {
			printf("%0.7lf", max(0.0, cur.px));
			break;
		}
		for (int k = 0; k < 4; ++k) {
			int nx = cur.py.px + dx[k];
			int ny = cur.py.py + dy[k];
			if (inRange(nx, ny) && canMove(cur.py.px, cur.py.py, nx, ny)) {
				double curh = h - max(0.0, cur.px) * 10;
				double delta = 0;
				double curt = cur.px;
				if (cl[nx][ny] - curh < 50) {
					delta = (curh - cl[nx][ny] + 50) / 10;
				}
				if (abs(delta) < EPS && abs(cur.px + 1) < EPS) {
					delta = 0;
				} else {
					curt = max(0.0, curt);
					double nh = min(curh, cl[nx][ny] - 50.0);
					if (nh - fl[cur.py.px][cur.py.py] < 20) {
						delta += 10;
					} else {
						delta += 1;
					}
				}
				state ns = mp(curt + delta, mp(nx, ny));
				if (used.find(ns) == used.end()) {
					q.insert(ns);
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		cerr << i << endl;
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}
