#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 110;
const int dxy[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };


int w, n, m, f[MAXN][MAXN], c[MAXN][MAXN];


void read() {
	scanf ("%d%d%d", &w, &n, &m);
	forn(i,n)
		forn(j,m)
			scanf ("%d", &c[i][j]);
	forn(i,n)
		forn(j,m)
			scanf ("%d", &f[i][j]);
}


int64 d[MAXN][MAXN];
set < pair<int64, pair<int,int> > > q;

void upd (int x, int y, int64 nd) {
	if (nd < d[x][y]) {
		q.erase (mp (d[x][y], mp (x, y)));
		d[x][y] = nd;
		q.insert (mp (d[x][y], mp (x, y)));
	}
}

bool inside (int x, int y) {
	return 0<=x && x<n && 0<=y && y<m;
}


void solve() {
	forn(i,n)
		forn(j,m)
			d[i][j] = INF64;
	upd (0, 0, 0);

	while (q.size()) {
		int x = q.begin()->sc.fs;
		int y = q.begin()->sc.sc;
		q.erase (q.begin());
		
		if (c[x][y] - max (w - d[x][y], f[x][y] + 0ll) < 50)
			throw;

		forn(dir,4) {
			int nx = x + dxy[dir][0];
			int ny = y + dxy[dir][1];
			if (! inside (nx, ny))
				continue;

			int64 l_wait = 0,
				r_wait = INF64;
			while (l_wait < r_wait) {
				int64 wait = (l_wait + r_wait) / 2;

				if (max (w - d[x][y] - wait, max (f[x][y], f[nx][ny]) + 0ll) > c[nx][ny] - 50 || f[nx][ny] > c[x][y] - 50)
					l_wait = wait + 1;
				else
					r_wait = wait;
			}
			int64 wait = l_wait;
			if (wait == INF64)
				continue;

			int water = (int) max (0ll, w - d[x][y] - wait - f[x][y]);
			int64 nd = d[x][y] + wait + (water>=20 ? 10 : 100);
			if (d[x][y] == 0 && wait == 0)
				nd = 0;
			upd (nx, ny, nd);
		}
	}

	if (d[n-1][m-1] == INF64)
		throw;
	printf ("%I64d.%I64d\n", d[n-1][m-1]/10, d[n-1][m-1]%10);
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	
	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		if (! cin)  throw;
		printf ("Case #%d: ", tt+1);
		solve();
	}

}