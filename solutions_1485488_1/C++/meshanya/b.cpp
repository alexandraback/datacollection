#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define taskname "b"
using namespace std;

const double eps = 1e-7;
const double inf = 1e9;
map< pair<int, int>, double > d;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
map< pair<int, int>, int > ceiling, flooring;
int n, m, H, t;

struct cmp_dist {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return (mp(d[a], a) < mp(d[b], b));
	}
};

bool good(pair<int, int> cur, pair<int, int> nxt) {
	if ((nxt.fs < 0) || (nxt.fs >= n) || (nxt.sc < 0) || (nxt.sc >= m)) return false;
	if (flooring[nxt] > ceiling[cur] - 50) return false;
	if (ceiling[nxt] < flooring[cur] + 50) return false;
	if (ceiling[nxt] < flooring[nxt] + 50) return false;
	return true;
}

double get_time(pair<int, int> cur, double curt, pair<int, int> nxt) {
	if (!good(cur, nxt)) return inf;
	if ((curt < eps) && (H + 50 <= ceiling[nxt])) return 0; 
	curt = max(curt, (H - ceiling[nxt] + 50) / 10.0);
	if (H - curt * 10 >= 20 + flooring[cur] - eps) curt += 1; else curt += 10;
	return curt;
}

void dijkstra(pair<int, int> start) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			d[mp(i, j)] = inf;
	d[start] = 0;
	set< pair<int, int>, cmp_dist > all;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			all.insert(mp(i, j));
	while (!all.empty()) {
		pair<int, int> cur = *all.begin();
		all.erase(cur);
		for (int dir = 0; dir < 4; ++dir) {
			pair<int, int> nxt = mp(cur.fs + dx[dir], cur.sc + dy[dir]);
			double t = get_time(cur, d[cur], nxt);
			if (d[nxt] > t) {
				all.erase(nxt);
				d[nxt] = t;
				all.insert(nxt);
			}
		}
	}
}

int main() {
	freopen(taskname".in", "r", stdin);
	freopen(taskname".out", "w", stdout);
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d%d", &H, &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &ceiling[mp(i, j)]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &flooring[mp(i, j)]);
		dijkstra(mp(0, 0));
		printf("Case #%d: %.10lf\n", it + 1, d[mp(n - 1, m - 1)]);
	}
	return 0;
}