#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l;};
int n, m, t;
int mth[1105];
bool e[1105][1105],vis[1105];

void init()
{
	rep(i, 1000) rep(j, 1000) e[i][j] = 0;

	n = 0; m = 0;
	int x, y;
	map<string, int> G1, G2;
	string st1, st2;
	char s1[25], s2[25];
	scanf("%d", &t);
	rep(i, t)
	{
		scanf("%s%s", s1, s2);
		st1 = string(s1);
		st2 = string(s2);
		if (G1[st1] == 0) {
			G1[st1] = ++n;
		}
		if (G2[st2] == 0) {
			G2[st2] = ++m;
		}
		x = G1[st1];
		y = G2[st2];
		e[x][y] = 1;
	}
}

bool Dfs(int k)
{
     int i;
     for (i=1;i<=m;i++)
         if (e[k][i]&&!vis[i])
         {
            vis[i]=1;
            if (!mth[i]||Dfs(mth[i]))
               {mth[i]=k;return 1;}
         }
     return 0;
}

int ans;
void work()
{
	ans = n + m;
	rep(i, m) mth[i] = 0, vis[i] = 0;
	rep(i, n)
	{
		if (Dfs(i)) --ans;
		rep(j, n) vis[j] = 0;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	rep(ca, T)
	{
		init();
		work();
		printf("Case #%d: %d\n", ca, t - ans);
	}
	return 0;
}