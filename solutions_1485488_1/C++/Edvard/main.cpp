#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 100 + 3;

int h, n, m;
int f[N][N], c[N][N];

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

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

ld d[N][N];

inline void solve(int test)
{
	cerr << "Test #" << test + 1 << endl;
	
	printf("Case #%d:", test + 1);
	
	forn(i, n)
		forn(j, m)
			d[i][j] = 1e18;
			
	queue<pt> q;
	queue<pt> qq;
	
	d[0][0] = 0.0;
	q.push(mp(0, 0));
	
	while (!q.empty())
	{
		int x = q.front().x, y = q.front().y;
		q.pop();
		
		qq.push(mp(x, y));
		
		forn(i, 4)
		{
			int xx = x + dx[i], yy = y + dy[i];
			
			if (!correct(xx, yy, n, m))
				continue;
				
			if (f[x][y] > c[xx][yy] - 50)
				continue;
				
			if (f[xx][yy] > c[xx][yy] - 50)
				continue;
				
			if (f[xx][yy] > c[x][y] - 50)
				continue;
				
			if (h > c[xx][yy] - 50)
				continue;
				
			if (d[xx][yy] > EPS)
			{
				d[xx][yy] = 0.0;
				q.push(mp(xx, yy));
			}
		}
	}
	
	q = qq;
	
	while (!q.empty())
	{
		int x = q.front().x, y = q.front().y;
		q.pop();
		
		forn(i, 4)
		{
			int xx = x + dx[i], yy = y + dy[i];
			
			if (!correct(xx, yy, n, m))
				continue;
				
			if (f[x][y] > c[xx][yy] - 50)
				continue;
				
			if (f[xx][yy] > c[xx][yy] - 50)
				continue;
				
			if (f[xx][yy] > c[x][y] - 50)
				continue;
				
			ld curt = d[x][y];
			ld w = max(ld(0), h - curt * 10);
			
			if (w - EPS > ld(c[xx][yy]) - 50)
				curt += (w - c[xx][yy] + 50) / 10;
				
			w = max(ld(0), h - curt * 10);
			
			ld cost = 10;
			
			if (ld(f[x][y]) < w - 20 + EPS)
				cost = 1;
				
			if (d[xx][yy] - EPS > curt + cost)
			{
				d[xx][yy] = curt + cost;
				q.push(mp(xx, yy));
			}
		}
	}
	
	ld ans = d[n - 1][m - 1];
	assert(ans < 5e17);
	
	printf(" %.10lf\n", double(ans));
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
        assert(read());
        solve(test);
    }
    
    return 0;
}
