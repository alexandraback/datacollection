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
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		int n;
		cin >> n;
		vector<pair<string, string> > v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i].first >> v[i].second;
		int ans = 0;
		for (int mask = 0; mask < (1 << n); ++mask)
		{
			set<string> s1, s2;
			for (int i = 0; i < n; ++i)
				if(mask & (1<<i))
				{
					s1.insert(v[i].first);
					s2.insert(v[i].second);
				}
			int cnt = 0;
			for (int i = 0; i < n; ++i)
				if ((mask & (1 << i)) == 0)
				{
					if(s1.find(v[i].first)==s1.end() || s2.find(v[i].second)==s2.end())
					{
						cnt = 0;
						break;
					}
					else cnt++;
				}
			ans = max(ans, cnt);
		}
		cout << "Case #" << tt << ": " << ans << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();

	return 0;
}