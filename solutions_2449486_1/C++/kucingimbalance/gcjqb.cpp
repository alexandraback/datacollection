#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>

#define sqr(x) ((x) * (x))
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const double PI = 2.0 * acos (0.0);
const int INF = 2123123123;
const int EPS = 1e-9;

typedef long long LL;

inline int NUM (char c) { return (int)c - 48; }
inline char CHAR (int n) { return (char)(n + 48); }
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

inline void OPEN(const string &s) 
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int ans,t,n,m,a[105][105], pat[105][105], mh;

int main()
{
	int i,j,k,tc;
	OPEN("gcjqb");
	
	scanf("%d", &t);
	for (tc = 1; tc <= t; tc++)
	{
		ans = 1;
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
			for (j = 0; j <m; j++) 
			{
				scanf("%d", &pat[i][j]);
				a[i][j] = 100;
			}
		for (k = 99; k > 0; k--)
		{
			for (i = 0; i < n; i++)
			{
				mh = 0;
				for (j = 0; j < m; j++) mh = max(mh,pat[i][j]);
				if (mh <= k)	for (j = 0; j < m; j++) a[i][j] = k;
			}
			for (j = 0; j < m; j++)
			{
				mh = 0;
				for (i = 0; i < n; i++) mh = max(mh,pat[i][j]);
				if (mh <= k) for (i = 0; i < n; i++) a[i][j] = k;
			}
		}
		printf("Case #%d: ",tc);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) if (a[i][j] != pat[i][j]) ans = 0;
		if (ans) puts("YES");
		else puts("NO");
	}
}