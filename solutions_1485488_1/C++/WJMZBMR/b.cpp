#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100 + 10;

double dist[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];

int n, m, H;

int low[MAX_N][MAX_N], up[MAX_N][MAX_N];

bool can(int r, int c, int nr, int nc, int w) {
	int l1 = low[r][c], r1 = up[r][c], l2 = low[nr][nc], r2 = up[nr][nc];
	if (w + 50 > r2)
		return false;
	if (l1 + 50 > r2)
		return false;
	if (l2 + 50 > r2)
		return false;
	if (l2 + 50 > r1)
		return false;
	return true;
}

int DX[4] = { 0, 0, -1, 1 }, DY[4] = { -1, 1, 0, 0 };

const int INF = ~0U >> 2;

bool used[MAX_N][MAX_N];

void work() {
	cin >> H >> n >> m;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			scanf("%d", up[r] + c);
		}
	}
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			scanf("%d", low[r] + c);
		}
	}

	queue<int> que;
	memset(vis, 0, sizeof vis);
	que.push(0);
	que.push(0);
	vis[0][0] = true;
	while (!que.empty()) {
		int r = que.front();
		que.pop();
		int c = que.front();
		que.pop();
		for (int d = 0; d < 4; ++d) {
			int nr = r + DX[d], nc = c + DY[d];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				if (can(r, c, nr, nc, H)) {
					if (!vis[nr][nc]) {
						vis[nr][nc] = true;
						que.push(nr);
						que.push(nc);
					}
				}
			}
		}
	}

	priority_queue<pair<int, int> > pq;
	memset(used, 0, sizeof used);

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (vis[r][c]) {
				dist[r][c] = 0;
				pq.push(make_pair(0, r * m + c));
			} else
				dist[r][c] = INF;
		}
	}

	while (!pq.empty()) {
		int me = pq.top().second;
		pq.pop();
		int r = me / m, c = me % m;
		if (used[r][c])
			continue;
		used[r][c] = true;
		int t = dist[r][c];
		if (r == n - 1 && c == m - 1) {
			cout << (double) t / 10 << endl;
			return;
		}

		for (int d = 0; d < 4; ++d) {
			int nr = r + DX[d], nc = c + DY[d];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				vector<int> ws;
				ws.push_back(t);
				ws.push_back(max(H - (up[nr][nc] - 50), 0));
				for (vector<int>::iterator e = ws.begin(); e != ws.end(); ++e) {
					int wait = *e;
					if (wait >= t) {
						if (can(r, c, nr, nc, H - wait)) {
							int nd = wait + ((H - wait - low[r][c]) >= 20 ? 10 : 100);
							if (nd < dist[nr][nc]) {
								dist[nr][nc] = nd;
								pq.push(make_pair(-nd, nr * m + nc));
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
