#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

bool valid(pair<int, int> x, int n, int m) {
	return 0 <= x.first && x.first < n && 0 <= x.second && x.second < m;
}

const int di[] = {0,  0,  1, -1};//-1, -1, -1};
const int dj[] = {1, -1,  0,  0};//-1, -1, 0, 1};

bool can_move2(int c, int f) {
	return f <= c - 50;
}

bool can_move1(int fcur, int fadj, int cadj) {
	return fcur <= cadj - 50 && fadj <= cadj - 50;
}


void solve() {
	int h, n, m;
	cin >> h >> n >> m;
	vector<vector<int> > c(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> c[i][j];
		}
	}
	vector<vector<int> > f(n, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> f[i][j];
		}
	}
	const int inf = 1000000;
	vector<vector<int> > dist(n, vector<int> (m, inf));
	dist[0][0] = 0;
	set<pair<int, pair<int, int> > > q;
	q.insert(make_pair(0, make_pair(0, 0)));

		while (!q.empty()) {
		pair<int, int> v = q.begin()->second;
		int cur_dist = q.begin()->first;
		q.erase(q.begin());
		for (int k = 0; k < 4; ++k) {
			int cur_water = h; //max(0, h - cur_dist);
			pair<int, int> to = make_pair(v.first + di[k], v.second + dj[k]);
			if (!valid(to, n, m)) continue;
			if (!can_move2(c[v.first][v.second], f[to.first][to.second])) continue;
			if (!can_move1(f[v.first][v.second], f[to.first][to.second], c[to.first][to.second])) continue;
			
			int need_water = max(0, c[to.first][to.second] - 50);
			
			int wait = 0;
			if (need_water < cur_water) continue;
			int dist_to = cur_dist + wait;
			if (dist_to < dist[to.first][to.second]) {
				if (dist[to.first][to.second] != inf) {
					q.erase(make_pair(dist[to.first][to.second], to));
				}
				dist[to.first][to.second] = dist_to;
				q.insert(make_pair(dist_to, to));
			}
		}
	}
		q.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (dist[i][j] != inf) {
					q.insert(make_pair(dist[i][j], make_pair(i, j)));
				}
			}
		}

	while (!q.empty()) {
		pair<int, int> v = q.begin()->second;
		int cur_dist = q.begin()->first;
		
		q.erase(q.begin());
		for (int k = 0; k < 4; ++k) {
			int cur_water = max(0, h - cur_dist);
			pair<int, int> to = make_pair(v.first + di[k], v.second + dj[k]);
			if (!valid(to, n, m)) continue;
			if (!can_move2(c[v.first][v.second], f[to.first][to.second])) continue;
			if (!can_move1(f[v.first][v.second], f[to.first][to.second], c[to.first][to.second])) continue;
			int need_water = max(0, c[to.first][to.second] - 50);
			int wait = 0;
			if (need_water < cur_water) {
				wait += cur_water - need_water;
				cur_water = need_water;
			}
			if (cur_water - f[v.first][v.second] >= 20) wait += 10;
			else wait += 100;
			int dist_to = cur_dist + wait;
			if (dist_to < dist[to.first][to.second]) {
				if (dist[to.first][to.second] != inf) {
					q.erase(make_pair(dist[to.first][to.second], to));
				}
				dist[to.first][to.second] = dist_to;
				q.insert(make_pair(dist_to, to));
			}
		}
	}

	cout << fixed << setprecision(1) << dist[n - 1][m - 1] / 10.0;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
	return 0;
}