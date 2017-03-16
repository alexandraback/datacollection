#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define sc second
#define ft first

#define FOR(i,N) for (int i=1; i<=N; i++)
#define REP(i,l,r) for (int i=l; i<=r; i++)

#define INF ~0U>>1
#define eps 1e-9

int n, T;
long long m;

const int maxn = 100;
int G[maxn][maxn];

int main ()
{
#ifndef ONLINE_JUDGE
#ifndef MEKTPOY
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
#else
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
#endif
	cin >> T;
	for (int test = 1; test <= T; test ++)
	{
		printf ("Case #%d: ", test);
		cin >> n >> m;
		memset (G, 0, sizeof(G));
		for (int i = 1; i <= n - 1; i ++)
			for (int j = i + 1; j <= n - 1; j ++)
				G[i][j] = 1;
		if (m > 1LL << (n - 2))
		{
			puts("IMPOSSIBLE");
			continue;
		}
		else
		{
			puts("POSSIBLE");
		}
		if (m == 1LL << (n - 2))
			for (int i = 1; i < n; i ++)
				G[i][n] = 1;
		else
		{
			int cnt = 2;
			for (; m; m >>= 1)
			{
				if (m & 1) G[cnt][n] = 1;
				cnt ++;
			}
		}
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= n; j ++)
				printf ("%d", G[i][j]);
			puts("");
		}
	}
	return 0;
}
