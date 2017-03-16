#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forn1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define fs first
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned char byte;
typedef vector<vector<int> > matrix;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 100 + 3;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int n, m, h;
int c[N][N], f[N][N];

inline bool read()
{
	if (scanf("%d%d%d", &h, &n, &m) != 3) 
		return false;

	forn(i, n)
		forn(j, m)
			assert(scanf("%d", &c[i][j]) == 1);

	forn(i, n)
		forn(j, m)
			assert(scanf("%d", &f[i][j]) == 1);

	return true;
}

ld d[N][N];

inline ld bfs()
{
	forn(i, n)
		forn(j, m)
			d[i][j] = ld(1e9);

	d[0][0] = 0.0;

	queue<pt> q;

	q.push(mp(0, 0));

	while(!q.empty())
	{
		int x = q.front().ft;
		int y = q.front().sc;

		q.pop();

		ld& dv = d[x][y];
		
		ld nowh = max(ld(0.0), h - 10 * dv);

		forn(i, 4)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (!correct(xx, yy, n, m))
				continue;

			if (!(f[x][y] + 50 <= c[xx][yy]))
				continue;

			ld cost = 0.0;

			{
				ld cur = max(ld(f[x][y]), nowh);
				ld need = min(cur, ld(c[xx][yy] - 50));

				assert(need < ld(c[xx][yy]) + EPS);

				cost = max(cost, (cur - need) / 10.0);
			}

			if (!(f[xx][yy] + 50 <= c[xx][yy]))
				continue;

			{
				ld cur = max(ld(f[xx][yy]), nowh);
				ld need = min(cur, ld(c[xx][yy] - 50));

				assert(need < ld(c[xx][yy]) + EPS);

				cost = max(cost, (cur - need) / 10.0);
			}

			/*if (!(f[x][y] + 50 <= c[x][y]))
				continue;

			{
				ld cur = max(ld(f[x][y]), nowh);
				ld need = min(cur, ld(c[x][y] - 50));

				assert(need < ld(c[x][y]) + EPS);

				cost = max(cost, (cur - need) / 10.0);
			}*/

			if (!(f[xx][yy] + 50 <= c[x][y]))
				continue;

			{
				ld cur = max(ld(f[xx][yy]), nowh);
				ld need = min(cur, ld(c[x][y]));

				assert(need < ld(c[x][y]) + EPS);

				cost = max(cost, (cur - need) / 10.0);
			}

			ld nexth = max(ld(0.0), nowh - cost * 10.0);

			ld rem = nexth - f[x][y];

			ld add = (rem > 20.0 - EPS)? 1.0: 10.0;

			{
				if (abs(dv) < EPS && abs(cost) < EPS)
					add = 0.0;

				if (d[xx][yy] > dv + cost + add)
				{
					d[xx][yy] = dv + cost + add;
					q.push(mp(xx, yy));
				}
			}
		}
	}

	return d[n - 1][m - 1];
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	ld ans = bfs();

	assert(ans < ld(5e8));

	cout << setprecision(10) << fixed;

	cout << ans << endl;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCnt;

    assert(scanf("%d\n", &testCnt) == 1);

    forn(test, testCnt)
    {
    	assert(read());
		solve(test);
	}

    return 0;
}
