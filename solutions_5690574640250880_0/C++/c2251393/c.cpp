
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define DEBUG 1
#define fst first
#define snd second
 
using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);
 
// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~

const int MAXR = 55;
const int MAXC = 55;

int r, c, m;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

// 0:dirty, 1:soldier, 2:clean
int mark[MAXR][MAXC];

inline bool exist(int x, int y)
{
	return 0 < x && x <= r && 0 < y && y <= c;
}

inline int cntDirty(int x, int y)
{
	int res = 0;
	REP(k, 0, 7)
		if(exist(x+dx[k], y+dy[k]))
			res += mark[x+dx[k]][y+dy[k]] == 0;
	return res;
}

char ans[MAXR][MAXC];

bool go(int x, int y, int tot)
{
	if(tot > r*c-m) return 0;
	if(tot == r*c-m)
		return 1;
	mark[x][y] = 2;
	vector<int> use;
	int adj = 0;
	REP(k, 0, 7)
	{
		int tx = x+dx[k];
		int ty = y+dy[k];
		if(exist(tx, ty) && mark[tx][ty] == 0)
		{
			adj++;
			mark[tx][ty] = 1;
			use.push_back(k);
		}
	}
	FOR(it, use)
	{
		bool tmp = go(x+dx[*it], y+dy[*it], tot+adj);
		if(tmp == 1) return 1;
	}
	FOR(it, use)
		mark[x+dx[*it]][y+dy[*it]] = 0;
	return 0;
}

inline void print(int x, int y)
{
	REP(i, 1, r)
	{
		REP(j, 1, c)
			if(mark[i][j] == 0) printf("*");
			else if(i == x && j == y) printf("c");
			else printf(".");
		puts("");
	}
}

inline void solve()
{
	REP(i, 1, r) REP(j, 1, c) 
	{
		fill((int*)mark, (int*)mark+MAXR*MAXC, 0);
		if(go(i, j, 1))
		{
			mark[i][j] = 2;
			print(i, j);
			return ;
		}
	}
	puts("Impossible");
	return ;
}

int main()
{
	int t;
	scanf("%d", &t);
	REP(__, 1, t)
	{
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", __);
		solve();
	}
}
