#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef vector< vector<ll> > VVI;
typedef pair<ll, ll> PII;
typedef vector<PII> VPII;

#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define RFOR(i, x, y) for(int i = x; i >= y; --i)
#define SZ(a) (ll)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x,0,sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define sqr(x) (x)*(x)
#define X first
#define Y second
#define y1 Y1
#define y2 Y2	
const long double pi=acos(-1.0);
const long double eps = 1e-9;

char a[400][400];
bool sw;
int r, c, m;
bool solve()
{
	cin >> r >> c >> m;
	if (r * c < m) return false;
	CLEAR(a);
	sw = false;
	if (r > c)
	{
		sw = true;
		swap(r, c);
	}
	if (r == 1)
	{
		a[1][1] = 'c';
		REP(i, m) a[1][c - i] = '*';
		return true;
	}
	if (r * c - m == 1)
	{
		FOR(i, 1, r) FOR(j, 1, c) a[i][j] = '*';
		a[1][1] = 'c';
		return true;
	}
	if (r * c - m < 4 || r * c - m == 7 || r * c - m == 5)
	{
		return false;
	} 
	
	int clear = r * c - m;
	FOR(dx, 1, r)
		FOR(dy, 1, c)
		{
			if (dx * dy < clear) continue;
			
			FOR(i, 1, r)
				FOR(j, 1, c)
					a[i][j] = '*';
			
			FOR(i, 1, dx)
				FOR(j, 1, dy)
					a[i][j] = '.';
			
			int tf = dx * dy - clear;
			FOR(d, 2, dx + dy)
				FOR(i, 1, dx)
					FOR(j, 1, dy)
						if ((dx + dy + 2 - i - j) == d && tf)
						{
							--tf;
							a[i][j] = '*';
						}
			FOR(i, 1, dx)
				FOR(j, 1, dy)
					if (a[i][j] == '.')
					{
						bool ok = true;
						FOR(u, i - 1, i + 1)
							FOR(v, j - 1, j + 1)
								if (u >= 1 && u <= r && v >= 1 && v <= c && a[u][v] == '*')
									ok = false;
						FOR(j, 1, c) if (a[1][j] == '.' && r > 1 && a[2][j] == '*') ok = false;
						FOR(i, 1, r) if (a[i][1] == '.' && c > 1 && a[i][2] == '*') ok = false;
						if (ok)
						{
							a[i][j] = 'c';
							return true;
						}
					}
					
		}
		
	FOR(dx, 1, r)
		FOR(dy, 1, c)
		{
			if (dx * dy < clear) continue;
			
			FOR(i, 1, r)
				FOR(j, 1, c)
					a[i][j] = '*';
			
			FOR(i, 1, dx)
				FOR(j, 1, dy)
					a[i][j] = '.';
			
			int tf = dx * dy - clear;
			FOR(d, 2, dx + dy)
					FOR(j, 1, dy)
				FOR(i, 1, dx)
			
						if ((dx + dy + 2 - i - j) == d && tf)
						{
							--tf;
							a[i][j] = '*';
						}
			FOR(i, 1, dx)
				FOR(j, 1, dy)
					if (a[i][j] == '.')
					{
						bool ok = true;
						FOR(u, i - 1, i + 1)
							FOR(v, j - 1, j + 1)
								if (u >= 1 && u <= r && v >= 1 && v <= c && a[u][v] == '*')
									ok = false;
						FOR(j, 1, c) if (a[1][j] == '.' && r > 1 && a[2][j] == '*') ok = false;
						FOR(i, 1, r) if (a[i][1] == '.' && c > 1 && a[i][2] == '*') ok = false;
						if (ok)
						{
							a[i][j] = 'c';
							return true;
						}
					}
					
		}
	
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
	int tests;
	cin >> tests;
	FOR(test, 1, tests)
	{
		printf("Case #%d:\n", test);
		if (!solve())
			cout << "Impossible\n";
		else
		{
			FOR(i, 1, r)
			FOR(j, 1, c)
				if (a[i][j] == 0) a[i][j] = '.';
				
			if (!sw)
			FOR(i, 1, r)
			{
				FOR(j, 1, c) cout << a[i][j];
				cout << "\n";
			}
			else
			FOR(j, 1, c)
			{
				FOR(i, 1, r) cout << a[i][j];
				cout << "\n";
			}	
		}
	}
}
