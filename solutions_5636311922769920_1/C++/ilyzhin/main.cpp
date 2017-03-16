#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <cassert>
#include <ctime>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pr(x) printf("%d ", x)
#define nl() printf("\n")
#define mp(x, y) make_pair(x, y)
#define forn(i, a, b) for(int i=a; i<b; ++i)
#define ford(i, a, b) for(int i=b-1; i>=a; --i)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9;

void solve()
{
	int t;
	sc(t);
	forn(tt, 0, t)
	{
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		if (s == k)
		{
			printf("Case #%d:", tt + 1);
			for (int i = 1; i <= s; ++i)
				printf(" %d", i);
			nl();
		}
		else
		{
			ll needed = k / c + (k%c == 0 ? 0 : 1);
			if (needed > s)
				printf("Case #%d: IMPOSSIBLE\n", tt + 1);
			else
			{
				printf("Case #%d:", tt+1);
				for (ll i = 0; i < needed; ++i)
				{
					ll offset = 0;
					for (ll j = i*c; j < (i + 1)*c; ++j)
					{
						offset *= k;
						if (j < k)
							offset += j;
					}
					printf(" %I64d", offset + 1);
				}
				nl();
			}
		}
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	solve();

	return 0;
}