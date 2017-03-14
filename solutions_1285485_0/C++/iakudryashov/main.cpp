#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define X first
#define Y second
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long double ld;
typedef pair<ld, ld> ptd;
typedef pair <int, int> pt;
typedef long long li;
typedef unsigned char byte;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;
const int INF = 1000 * 1000 * 1000;

const int N = 30 + 3;

int h, w, sx, sy, d;
char f[N][N];
vector <pt> was;

bool between (const pt& a, const pt& b, const pt& c)
{
	if (c.X < min(a.X, b.X) || c.X > max(a.X, b.X))
		return false;
		
	if (c.Y < min(a.Y, b.Y) || c.Y > max(a.Y, b.Y))
		return false;
		
	return true;
}

inline int dist2 (int ax, int ay, int bx, int by)
{
	return sqr(ax - bx) + sqr(ay - by);
}

inline bool check (int px, int py)
{
	pt a = mp(sx, sy), b = mp(px, py);
	
	int A = b.Y - a.Y, B = a.X - b.X, C = -(A * a.X + B * a.Y);
	
	forn(i, sz(was))
	{
		int s = A * was[i].X + B * was[i].Y + C;
		if (s != 0) continue;
		
		if (between(a, b, was[i]))
			return false;
	}
	
	return true;
}

int solve ()
{
	int res = 0;
	was.clear();
	
	for (int x = 0; ; x++)
	{
		int fx = ((x & 1) ? w * (x + 1) - sx : w * x + sx);
		if (abs(fx - sx) > d) break;
		
		for (int y = 0; ; y++)
		{
			if (x == 0 && y == 0) continue;
			int fy = ((y & 1) ? h * (y + 1) - sy : h * y + sy);
			
			if (dist2(sx, sy, fx, fy) > d * d) break;
			
			if (check(fx, fy))
			{
				res++;
				was.pb(mp(fx, fy));
			}
		}
		
		for (int y = -1; ; y--)
		{
			int fy = ((abs(y) & 1) ? h * (y + 1) - sy : h * y + sy);
			
			if (dist2(sx, sy, fx, fy) > d * d) break;
			
			if (check(fx, fy))
			{
				res++;
				was.pb(mp(fx, fy));
			}
		}
	}
	
	for (int x = -1; ; x--)
	{
		int fx = ((abs(x) & 1) ? w * (x + 1) - sx : w * x + sx);
		if (abs(fx - sx) > d) break;
		
		for (int y = 0; ; y++)
		{
			if (x == 0 && y == 0) continue;
			int fy = ((y & 1) ? h * (y + 1) - sy : h * y + sy);
			
			if (dist2(sx, sy, fx, fy) > d * d) break;
			
			if (check(fx, fy))
			{
				res++;
				was.pb(mp(fx, fy));
			}
		}
		
		for (int y = -1; ; y--)
		{
			int fy = ((abs(y) & 1) ? h * (y + 1) - sy : h * y + sy);
			
			if (dist2(sx, sy, fx, fy) > d * d) break;
			
			if (check(fx, fy))
			{
				res++;
				was.pb(mp(fx, fy));
			}
		}
	}
	
	return res;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{
		scanf("%d%d%d", &h, &w, &d);
		forn(i, h)
			scanf("%s", f[i]);
			
		sx = -1, sy = -1;
		forn(i, h)
			forn(j, w)
				if (f[i][j] == 'X')
					sx = i, sy = j;
					
		h -= 2, w -= 2, sx--, sy--; { int oldsx = sx; sx = sy; sy = h - 1 - oldsx; }
		
		h *= 2, w *= 2, sx = sx * 2 + 1, sy = sy * 2 + 1, d *= 2;
		
		printf("Case #%d: %d\n", test + 1, solve());
	}

	return 0;
}
























































