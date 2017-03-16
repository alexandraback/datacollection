/* 
	Template Fimbulvetr ver 0.11
	In the darkness, I will find peace. 
	Author: Falsyta
	Date: March 4th, 2015
*/
 
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <cmath>
# include <algorithm>
# include <queue>
# include <vector>
# include <map>
# include <set>
# include <string>
 
# define REP(i, n) for (int i = 1; i <= n; i ++)
# define REP_0(i, n) for (int i = 0; i < n; i ++)
# define REP_0N(i, n) for (int i = 0; i <= n; i ++)
# define REP_D(i, n) for (int i = n; i > 0; i --)
# define REP_D0(i, n) for (int i = n - 1; i >= 0; i --)
# define REP_D0N(i, n) for (int i = n; i >= 0; i --)
# define REP_G(i, x) for (int i = pos[x]; i; i = g[i].frt)
# define FOR(i, a, b) for (int i = a; i <= b; i ++)
# define DWN(i, a, b) for (int i = b; i >= a; i --)
# define RST(a) memset (a, 0, sizeof (a))
# define CLR(a, x) memset (a, x, sizeof (a))
# define CPY(a, b) memcpy (a, b, sizeof (a))
 
# define pii pair <int, int>
# define pll pair <LL, LL>
# define pb push_back
# define mp make_pair
# define v1 first
# define v2 second
 
using namespace std;
 
typedef long long LL;
typedef long double DB;
 
const int inf = 1 << 27; 
const LL lnf = 1LL << 55;

template <class T1, class T2> bool RlxN (T1 &x, T2 y) {if (x > y) {return x = y, 1;} return 0;}
template <class T1, class T2> bool RlxX (T1 &x, T2 y) {if (x < y) {return x = y, 1;} return 0;}

int n, q0, a[1010];
int main ()
{
	//freopen ("B.in", "r", stdin);
	//freopen ("B.out", "w", stdout);
	scanf ("%d", &q0);
	REP (p, q0)
	{
		int ans = inf, M = 0;
		scanf ("%d", &n);
		REP (i, n) scanf ("%d", &a[i]), RlxX (M, a[i]);
		REP (t, M)
		{
			int ext = 0;
			REP (i, n) ext += (a[i] + t - 1) / t - 1;
			RlxN (ans, t + ext);
		}
		printf ("Case #%d: %d\n", p, ans);
	}
	return 0;
}