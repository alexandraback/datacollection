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

const int N = 100 + 3;

int H, n, m;
int c[N][N], f[N][N];
ld d[N][N];
int inQ[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve (int test)
{	
	forn(i, n)
		forn(j, m)
			d[i][j] = 1e9;
			
	queue <pt> q;
	q.push(mp(0, 0));
	inQ[0][0] = true;
	d[0][0] = 0.0;
	
	while (!q.empty())
	{
		int x = q.front().ft, y = q.front().sc;
		q.pop();
		inQ[x][y] = false;
		
		ld dv = d[x][y];
		
		forn(i, 4)
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (!correct(tx, ty, n, m)) continue;
			
			if (c[tx][ty] - 50 < f[tx][ty]) continue;
			
			if (c[tx][ty] - 50 < f[x][y]) continue;
			
			if (c[x][y] - 50 < f[tx][ty]) continue;
			
			ld curWater = max(ld(0), H - dv * 10.0);
			
			//if (c[tx][ty] - 50 + EPS < curWater) continue;
			
			ld cost = 1.0;
			if (abs(dv) < EPS && curWater < c[tx][ty] - 50 + EPS)
				cost = 0.0;
			else
			{
				ld needWater = c[tx][ty] - 50;
				
				cost += max(ld(0), (curWater - needWater) / 10.0);
				curWater = min(curWater, needWater);
			
				if (f[x][y] + 20 > curWater + EPS)
					cost += 9.0;
			}
			
			if (d[tx][ty] > dv + cost + EPS)
			{
				d[tx][ty] = dv + cost;
				
				if (!inQ[tx][ty])
				{
					inQ[tx][ty] = true;
					q.push(mp(tx, ty));
				}
			}
		}
	}
	
	assert(d[n - 1][m - 1] < 5e8);
	
	printf("Case #%d: %.10lf\n", test + 1, double(d[n - 1][m - 1]));
}

void read ()
{
	scanf("%d%d%d", &H, &n, &m);
	
	forn(i, n)
		forn(j, m)
			scanf("%d", &c[i][j]);
			
	forn(i, n)
		forn(j, m)
			scanf("%d", &f[i][j]);
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{
		read();
		solve(test);
	}

	return 0;
}
























































