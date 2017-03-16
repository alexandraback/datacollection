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

short ord[400];
short g[5][5] = 
{
	{0, 0, 0, 0, 0}, 
	{0, 1, 2, 3, 4}, 
	{0, 2, -1, 4, -3}, 
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

const int NR = 2000000;
struct Info
{
	short val;
	bool sgn;
	Info () {val = sgn = 0;}
	Info (short v, bool s) {val = v, sgn = s;}
	Info operator * (Info b) {return Info (short (abs (g[val][b.val])), sgn ^ b.sgn ^ (g[val][b.val] < 0));}
	void operator *= (Info b) {sgn ^= b.sgn ^ (g[val][b.val] < 0), val = abs (g[val][b.val]);}
	bool operator == (Info b) {return val == b.val && sgn == b.sgn;}
	bool operator != (Info b) {return val != b.val || sgn != b.sgn;}
} pl[NR], pr[NR], a[NR];
int q0, l;
LL t;
char s[NR];
Info Pow (Info a, LL z) {Info s = Info (1, 0); do {if (z & 1) s *= a; a *= a;} while (z >>= 1); return s;}

int main ()
{
	//freopen ("C.in", "r", stdin);
	//freopen ("C.out", "w", stdout);
	scanf ("%d", &q0);
	ord['i'] = 2, ord['j'] = 3, ord['k'] = 4;
	REP (p, q0)
	{
		scanf ("%d%lld%s", &l, &t, s + 1);
		LL L = l * t;
		REP (i, l) a[i] = Info (ord[s[i]], 0);
		pl[0] = pr[l + 1] = Info (1, 0);
		REP (i, l) pl[i] = pl[i - 1] * a[i];
		REP_D (i, l) pr[i] = a[i] * pr[i + 1];
		
		Info w = pl[0], iV = Info (2, 0), kV = Info (4, 0);
		int len = 0; 
		LL iL = -1, kL = -1;
		if (Pow (pl[l], t) != Info (1, 1)) {printf ("Case #%d: NO\n", p); continue;}
		//printf ("%d %d\n", pr[5].val, pr[5].sgn);

		while (w != pl[0] || !len)
		{
			REP (i, l) if (w * pl[i] == iV) {iL = len * l + i; break;}
			if (iL != -1) break;
			w *= pl[l], len ++;
		}
		if (iL == -1) {printf ("Case #%d: NO\n", p); continue;}

		w = pl[0], len = 0;
		while (w != pl[0] || !len)
		{
			REP (i, l) if (pr[l - i + 1] * w == kV) {kL = len * l + i; break;}
			if (kL != -1) break;
			w *= pl[l], len ++;
		}
		//printf ("%lld\n", kL);
		if (kL == -1) {printf ("Case #%d: NO\n", p); continue;}
		//printf ("called %lld %lld\n", iL, kL);

		if (iL + kL < L) printf ("Case #%d: YES\n", p);
		else printf ("Case #%d: NO\n", p);
	}
	return 0;
}