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
		if(s==k)
		{
			printf("Case #%d:", tt + 1);
			for (int i = 1; i <= s; ++i)
				printf(" %d", i);
			nl();
		}
		else
		{
			printf("Case #%d: IMPOSSIBLE\n", tt + 1);
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	solve();

	return 0;
}