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
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
 
#define REP(i, n) for(int i = 0; i < n; ++i)
#define RREP(i, n) for(int i = n - 1; i >= 0; --i)
#define FOR(i, x, y) for(ll i = x; i <= y; ++i)
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
const int MAXN = 201011;
const int INF = 1000000000;
const ll MOD = 1000000007;
 
int ans = INF;
int n, m, k;
int a[30][30];
int unc[30][30];

void fill_grid(int mask)
{
	// cout << "mask: " << mask << endl;
	FOR(i, 1, n)
		FOR(j, 1, m)
		{
			int k = (i - 1) * m + j - 1;	
			// cout << "k: " << k << endl;
			if (mask & (1 << k))
			{
				a[i][j] = 1;
				// cout << i << " " << j << endl;
			}
			else a[i][j] = 0;
		}
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
	if (a[x][y] || unc[x][y]) return;
	unc[x][y] = true;
	REP(dd, 4)
		{
			int xx = x + dx[dd];
			int yy = y + dy[dd];
			if (1 <= xx && xx <= n && 1 <= yy && yy <= m)
				if (!a[xx][yy] && !unc[xx][yy])
					dfs(xx, yy);
		}
}

void check()
{
	FOR(i, 1, n)
		FOR(j, 1, m)
			unc[i][j] = 0;
	FOR(i, 1, n)
	{
		dfs(i, 1);
		dfs(i, m);
	}
	FOR(j, 1, m)
	{
		dfs(1, j);
		dfs(n, j);
	}
	int cnt_points = 0;
	int closed = n * m;
	FOR(i, 1, n)
		FOR(j, 1, m)
		{
			if (unc[i][j]) --closed;
			if (a[i][j]) ++cnt_points;
		}
	// cout << closed << endl;
	// cout << cnt_points << endl;
	// cout << cnt_points << endl;
	if (closed >= k) ans = min(ans, cnt_points);
}

int main()
{   
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int tests;
	scanf("%d\n", &tests);
	FOR(test, 1, tests)
	{
		ans = INF;
		cin >> n >> m >> k;
		REP(mask, 1 << (n * m))
		{
			fill_grid(mask);
			// a[1][2] = a[1][3] = a[1][4] = a[2][1] = a[2][5] = a[3][2] = a[3][3] = a[3][4] = 1;
			check();
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
} 
