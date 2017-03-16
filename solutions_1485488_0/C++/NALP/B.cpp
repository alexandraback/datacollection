#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>

#include <iostream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define y1 YYYYYYYYYYYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Abs(x) (((x) >= 0) ? (x) : (-(x)))

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 110;
const int dx[] = {-1, +1, 0, 0};
const int dy[] = {0, 0, -1, +1};

long double H, l[MAXN][MAXN], r[MAXN][MAXN], d[MAXN][MAXN];
bool used[MAXN][MAXN];
queue<int> qx, qy;
int n, m;

void read() {
	cin >> H >> n >> m;
	forn(i, n)
		forn(j, m)
			cin >> r[i][j];

	forn(i, n)
		forn(j, m)
			cin >> l[i][j];
}

bool valid(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}

void update(int x, int y, long double value) {
	if (d[x][y] > value) {
		if (!used[x][y]) {
			qx.push(x);
			qy.push(y);
		}

		used[x][y] = true;
		d[x][y] = value;
	}
}

long double get(long double l1, long double r1, long double l2, long double r2, long double t) {
	if (max(l1, l2) + 50 - EPS > min(r1, r2))
		return 1E20;

	t = max(t, (H - (r2 - 50)) / 10);
	if (t > EPS)
		if ((H - 10*t) + EPS > l1 + 20)
			t += 1;
		else
			t += 10;

	return t;
}

void solve() {
	forn(i, n)
		forn(j, m)
			d[i][j] = 1E20;

	update(0, 0, max((long double)0, (H - (r[0][0] - 50)) / 10.0));
	while (!qx.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		used[x][y] = false;

		forn(i, 4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (valid(xx, yy))
				update(xx, yy, get(l[x][y], r[x][y], l[xx][yy], r[xx][yy], d[x][y]));
		}
	}

	cout << d[n - 1][m - 1] << endl;
}

int main() {
#ifdef NALP_PROJECT
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#else
#endif

	cout.precision(9);
	cout.setf(ios::fixed);

	cerr.precision(3);
	cerr.setf(ios::fixed);

	int tests;
	cin >> tests;
	forn(i, tests) {
		cerr << "Test #" << i + 1 << endl;
		time_t curTime = clock();

		cout << "Case #" << i + 1 << ": ";
		read();
		solve();

		cerr << "calced : " << (clock() - curTime + 0.0) / CLOCKS_PER_SEC << endl << endl;
	}
	
	return 0;
}
