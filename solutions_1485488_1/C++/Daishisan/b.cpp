// includes
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// typedefs
typedef long long ll;
typedef long double ld;
typedef complex<double> pt;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

// macros
#define PRINT0(X) #X << " = " << (X)
#define PRINT1(X1) cout << PRINT0(X1) << endl;
#define PRINT2(X1, X2) cout << PRINT0(X1) << ", " << PRINT0(X2) << endl
#define PRINT3(X1, X2, X3) cout << PRINT0(X1) << ", " << PRINT0(X2) << ", " << PRINT0(X3) << endl
#define PRINT4(X1, X2, X3, X4) cout << PRINT0(X1) << ", " << PRINT0(X2) << ", " << PRINT0(X3) << ", " << PRINT0(X4) << endl
#define PRINTALL(COL) {cout << #COL << " ="; for (auto& printall_curr : (COL)) cout << " " << printall_curr;}

// stuff starts here
const int INF = (1 << 30);

int n, m;
int as[200][200];
int bs[200][200];
double ts[200][200];
int dn[4] = {-1,  0,  1,  0};
int dm[4] = { 0,  1,  0, -1};

struct S {
	int x;
	int y;
	double t;
	S(int _x, int _y, double _t) {
		x = _x;
		y = _y;
		t = _t;
	}
	bool operator<(const S& o) const {
		if (t != o.t)
			return t < o.t;
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
};

double go_time(double h, int a, int b, int c, int d, bool can_wait = true) {
	// invalid squares
	if (n <= a || a < 0 || m <= b || b < 0)
		return -1;
	if (n <= c || c < 0 || m <= d || d < 0)
		return -1;
	// other constraints
	if (bs[c][d] - as[a][b] < 50 || bs[c][d] - as[c][d] < 50)
		return -1;
	if (bs[a][b] - as[c][d] < 50)
		return -1;
	// we can move, so return time
	if (bs[c][d] - h >= 50)
		return (h - as[a][b] < 20) ? 10 : 1;
	if (can_wait) {
		double ret = (50 - (bs[c][d] - h))/10.0;
		return ret + ((bs[c][d] - 50 - as[a][b] < 20) ? 10 : 1);
	}
	return -1;
}

// main
int main() {
	int num_tests; cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		cout << "Case #" << test << ": ";
		// read in input
		int h; cin >> h >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> bs[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> as[i][j];
		// time to get to position
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ts[i][j] = INF;
		// simulate going anywhere we can at the beginning
		ts[0][0] = 0;
		stack<pii> all;
		all.push(make_pair(0, 0));
		while (!all.empty()) {
			pii curr = all.top();
			all.pop();
			int p = curr.first;
			int q = curr.second;
			for (int i = 0; i < 4; ++i) {
				int s = p + dn[i];
				int t = q + dm[i];
				if (go_time(h, p, q, s, t, false) > 0 && ts[s][t] == INF) {
					ts[s][t] = 0;
					all.push(make_pair(s, t));
				}
			}
		}
		// run dijkstra
		set<S> q;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				q.insert(S(i, j, ts[i][j]));
		while (!q.empty()) {
			S u = *q.begin();
			if (u.t == INF)
				break;
			q.erase(q.begin());
			for (int i = 0; i < 4; ++i) {
				int s = u.x + dn[i];
				int t = u.y + dm[i];
				if (go_time(h - 10*u.t, u.x, u.y, s, t) > 0) {
					double alt = u.t + go_time(h - 10*u.t, u.x, u.y, s, t);
					if (alt < ts[s][t]) {
						q.erase(S(s, t, ts[s][t]));
						ts[s][t] = alt;
						q.insert(S(s, t, ts[s][t]));
					}
				}
			}
		}
		printf("%.7f\n", ts[n - 1][m - 1]);
	}
}

