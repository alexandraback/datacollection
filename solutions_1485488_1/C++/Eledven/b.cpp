#include <iostream>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <iomanip>
#define nextLine() { for (int c = getchar(); c != '\n' && c != EOF; c = getchar()); }
#define sqr(a) ((a)*(a))
#define has(mask,i) (((mask) & (1<<(i))) == 0 ? false : true)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long long LL;
typedef long double ldb;

const int INF = (1 << 30) - 1;
const ldb EPS = 1e-9;
const ldb PI = fabs(atan2(0.0, -1.0));
const ldb LDBINF = 1e54;
const int MAXN = 105;
const ldb SPEED = 10.0;

int sh, n, m;
int ch[MAXN][MAXN];
int cf[MAXN][MAXN];
void load()
{
	scanf("%d%d%d", &sh, &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &ch[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &cf[i][j]);
	}	
}

bool good(int i, int j)
{
	return 0 <= i && i < n && 0 <= j && j < m;
}

const int di[4] = {-1, 0,  0, 1};
const int dj[4] = { 0, 1, -1, 0};

class State
{
	public:
		int i, j;
		int down;

		State() {};

		State(int i, int j, int down)
		{
			this->i = i;
			this->j = j;
			this->down = down;
		}

		inline State move(int dir) const
		{
			return State(i + di[dir], j + dj[dir], down);
		}

		inline State startDown() const
		{
			return State(i, j, 1);
		}
};

bool operator < (const State &a, const State &b)
{
	if (a.i != b.i) return a.i < b.i;
	if (a.j != b.j) return a.j < b.j;
	return a.down < b.down;
}

ldb d[MAXN][MAXN][2];

bool canMove(int si, int sj, int fi, int fj, ldb h)
{
	if (ch[fi][fj] - cf[si][sj] < 50) return false;
	if (ch[fi][fj] - cf[fi][fj] < 50) return false;
	if (ch[fi][fj] - h + EPS < 50) return false;
	return ch[si][sj] - cf[fi][fj] >= 50;
}

ldb needToWait(int si, int sj, int fi, int fj, ldb h)
{
	if (ch[fi][fj] - cf[si][sj] < 50) return LDBINF;
	if (ch[fi][fj] - cf[fi][fj] < 50) return LDBINF;
	if (ch[si][sj] - cf[fi][fj] < 50) return LDBINF;
	ldb a = ch[fi][fj];
	return (50 + h - a) / SPEED;
}

void solve(int test)
{
	set < pair<ldb, State> > h;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			d[i][j][0] = LDBINF;
			d[i][j][1] = LDBINF;
		}
	}

	d[0][0][0] = 0.0;
	h.insert(mp(0.0, State(0, 0, 0)));

	while (!h.empty())
	{
		State cur = h.begin()->se;
		//eprintf("State: %d %d %d d = %.10lf\n", cur.i, cur.j, cur.down, (double)d[cur.i][cur.j][cur.down]);
		h.erase(h.begin());

		if (cur.i == n - 1 && cur.j == m - 1)
		{
			printf("Case #%d: %.10lf\n", test, (double)d[cur.i][cur.j][cur.down]);
			return;
		}

		State ncur = cur.startDown();
		if (d[ncur.i][ncur.j][ncur.down] > d[cur.i][cur.j][cur.down])
		{
			h.erase(mp(d[ncur.i][ncur.j][ncur.down], ncur));
			d[ncur.i][ncur.j][ncur.down] = d[cur.i][cur.j][cur.down];
			h.insert(mp(d[ncur.i][ncur.j][ncur.down], ncur));
		}

		ldb ch = sh - SPEED * d[cur.i][cur.j][cur.down];
		if (ch < EPS) ch = 0.0;

		for (int dir = 0; dir < 4; dir++)
		{
			ncur = cur.move(dir);
			if (!good(ncur.i, ncur.j)) continue;
			if (canMove(cur.i, cur.j, ncur.i, ncur.j, ch))
			{
				ldb cost;
				if (!ncur.down) cost = 0.0;
				else
				{
					if (ch - cf[cur.i][cur.j] + EPS > 20.0) cost = 1.0;
					else cost = 10.0;
				}
				
				if (d[ncur.i][ncur.j][ncur.down] > d[cur.i][cur.j][cur.down] + cost)
				{
					h.erase(mp(d[ncur.i][ncur.j][ncur.down], ncur));
					d[ncur.i][ncur.j][ncur.down] = d[cur.i][cur.j][cur.down] + cost;
					h.insert(mp(d[ncur.i][ncur.j][ncur.down], ncur));
				}
			}
			else
			{
				if (!ncur.down) continue;
				ldb wait = needToWait(cur.i, cur.j, ncur.i, ncur.j, ch);
				if (fabs(wait - LDBINF) < EPS) continue;

				ldb cch = sh - SPEED * (d[cur.i][cur.j][cur.down] + wait);
				if (cch < EPS) cch = 0.0;
				
				ldb cost = wait;
				if (cch - cf[cur.i][cur.j] + EPS > 20.0) cost += 1.0;
				else cost += 10.0;
				
				
				if (d[ncur.i][ncur.j][ncur.down] > d[cur.i][cur.j][cur.down] + cost)
				{
					h.erase(mp(d[ncur.i][ncur.j][ncur.down], ncur));
					d[ncur.i][ncur.j][ncur.down] = d[cur.i][cur.j][cur.down] + cost;
					h.insert(mp(d[ncur.i][ncur.j][ncur.down], ncur));
				}
			}
		}
	}

	throw 42;
}

int main()
{
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		load();
		solve(test);
	}	
	return 0;
}
