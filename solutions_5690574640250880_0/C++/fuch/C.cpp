#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>

#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef long long LL;

int R, C, M;
char mp[50][51];
int mines[50][50];
bool used[50][50];

int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dj[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void dfs(int i, int j)
{
	used[i][j] = true;
	if (mp[i][j] == '*' || mines[i][j] > 0) return;

	for (int d = 0; d < 8; ++d)
	{
		int ti = i + di[d], tj = j + dj[d];
		if (ti < 0 || ti >= R || tj < 0 || tj >= C) continue;
		if (used[ti][tj]) continue;
		if (mp[ti][tj] != '*') dfs(ti, tj);
	}
}

bool check(int si = 0, int sj = 0)
{
	memset(mines, 0, sizeof(mines));

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			for (int d = 0; d < 8; ++d)
			{
				int ti = i + di[d], tj = j + dj[d];
				if (ti < 0 || ti >= R || tj < 0 || tj >= C) continue;
				if (mp[ti][tj] == '*') ++mines[i][j];
			}
		}
	}

	memset(used, 0, sizeof(used));
	dfs(si, sj);

//	puts("Map:");
//	for (int i = 0; i < R; ++i)
//	{
//		mp[i][C] = 0;
//		puts(mp[i]);
//	}
//	puts("Mines:");
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j) printf("%d", mines[i][j]);
//		puts("");
//	}
//	puts("Used:");
//	for (int i = 0; i < R; ++i)
//	{
//		for (int j = 0; j < C; ++j) printf("%d", used[i][j]);
//		puts("");
//	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (used[i][j] != (mp[i][j] == '.')) return false;
		}
	}
	return true;
}

void solve()
{
	for (int s = 0; s < (1 << R * C); ++s)
	{
		int mines = 0;
		for (int i = 1; i <= s; i <<= 1)
		{
			if (i & s) ++mines;
		}
		if (mines != M) continue;

		int bit = 1;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				mp[i][j] = (s & bit) ? '*' : '.';
				bit <<= 1;
			}
		}
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (check(i, j))
				{
					mp[i][j] = 'c';
					for (int l = 0; l < R; ++l)
					{
						mp[l][C] = 0;
						puts(mp[l]);
					}
					return;
				}
			}
		}
	}
	puts("Impossible");
}

void solve_junk()
{
	for (int L = 1; L <= C; ++L)
	{
		int H = (R * C - M + L - 1) / L;
		if (H > R) continue;
		memset(mp, '*', sizeof(mp));
		for (int i = 0, k = R * C - M; k > 0; ++i)
		{
			for (int j = 0; j < L && k > 0; ++j, --k)
			{
				mp[i][j] = '.';
			}
		}
		if (check())
		{
			mp[0][0] = 'c';
			for (int i = 0; i < R; ++i)
			{
				mp[i][C] = 0;
				puts(mp[i]);
			}
			return;
		}
	}
	for (int L = 1; L <= C; ++L)
	{
		int H = (R * C - M + L - 1) / L;
		if (H > R) continue;
		memset(mp, '*', sizeof(mp));
		for (int j = 0, k = R * C - M; k > 0; ++j)
		{
			for (int i = 0; i < H && k > 0; ++i, --k)
			{
				mp[i][j] = '.';
			}
		}
		if (check())
		{
			mp[0][0] = 'c';
			for (int i = 0; i < R; ++i)
			{
				mp[i][C] = 0;
				puts(mp[i]);
			}
			return;
		}
	}
	puts("Impossible");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		scanf("%d%d%d", &R, &C, &M);
		printf("Case #%d:\n", cs);
		solve();
	}
	return 0;
}
