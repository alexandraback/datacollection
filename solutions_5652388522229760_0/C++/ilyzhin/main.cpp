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

vector<int> getDigits(int x)
{
	vector<int> digits;
	while(x>0)
	{
		digits.push_back(x % 10);
		x /= 10;
	}
	return digits;
}

void solve()
{
	int t;
	sc(t);
	forn(tt, 0, t)
	{
		int n;
		sc(n);
		if (n == 0)
			printf("Case #%d: INSOMNIA\n", tt + 1);
		else
		{
			int x = n;
			vector<bool> used(10, false);
			while (true)
			{
				vector<int> digits = getDigits(x);
				for (auto d : digits)
					used[d] = true;
				bool all = true;
				for (int i = 0; i < 10; ++i)
					all = all && used[i];
				if (all) break;
				x += n;				
			}
			printf("Case #%d: %d\n", tt + 1, x);
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