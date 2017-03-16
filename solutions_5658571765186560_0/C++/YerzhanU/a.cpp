#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MAXN 21

int x, n, m;
int d[MAXN][1 << MAXN];

inline void go(int i, int j, int mask, int nmask, int val)
{
	if (j == m)
	{
		d[i + 1][nmask] |= val;
		return;
	}

	if ((mask >> j) & 1) 
	{
		go(i, j + 1, mask, nmask, val);
		return;
	}
	// |
	// |
	// |
	if (j + 2 < m && !((mask >> j) & 1) && !((mask >> (j + 1)) & 1) && !((mask >> (j + 2)) & 1))
		go(i, j + 3, mask, nmask, val | 2);
	// |-
	// |
	if (j + 1 < m && !((mask >> j) & 1) && !((nmask >> j) & 1) && !((mask >> (j + 1)) & 1))
		go(i, j + 2, mask, nmask | (1 << j), val | 4);
	// -|
	//  |
	if (j + 1 < m && !((mask >> j) & 1) && !((nmask >> j) & 1) && !((nmask >> (j + 1)) & 1))
		go(i, j + 1, mask, nmask | (1 << j) | (1 << (j + 1)), val | 4);
	//  |
	// -|
	if (j - 1 >= 0 && !((mask >> j) & 1) && !((nmask >> j) & 1) && !((nmask >> (j - 1)) & 1))
		go(i, j + 1, mask, nmask | (1 << j) | (1 << (j - 1)), val | 4);

}

inline void solve()
{
	scanf("%d%d%d", &x, &n, &m);
	if (x >= 4 || (n * m) % x != 0)
	{
		puts("RICHARD");
		return;
	}
	if (x <= 3)
	{
		puts("GABRIEL");
		return;
	}

/*	memset(d, 0, sizeof(d));
   d[0][0] = 1;
   for (int i = 0; i < n; ++i)
   	for (int mask = 0; mask < (1 << m); ++mask)
   		if (d[i][mask])
	   		go(i, 0, mask, 0, d[i][mask]);

	puts((d[n][0] == 7) ? "GABRIEL" : "RICHARD");*/
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		printf("Case #%d: ", t + 1);
		solve();
	}
	return 0;
}
