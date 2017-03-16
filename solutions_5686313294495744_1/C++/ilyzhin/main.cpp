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

int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;
map<string, int> mapa1;
map<string, int> mapa2;

bool try_kuhn(int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

void solve()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		int tops;
		sc(tops);
		vector<pair<string, string> > v(tops);
		n = k = 0;
		mapa1.clear();
		mapa2.clear();
		for (int i = 0; i < tops; ++i)
		{
			char buf1[25], buf2[25];
			scanf("%s %s", buf1, buf2);
			v[i].first = string(buf1);
			v[i].second = string(buf2);
			if (mapa1.find(v[i].first) == mapa1.end())
				mapa1[v[i].first] = n++;
			if (mapa2.find(v[i].second) == mapa2.end())
				mapa2[v[i].second] = k++;
		}
		g.clear();
		g.resize(n);
		for (int i = 0; i < tops; ++i)
			g[mapa1[v[i].first]].push_back(mapa2[v[i].second]);
		mt.assign(k, -1);
		vector<char> used1(n);
		for (int i = 0; i<n; ++i)
			for (size_t j = 0; j<g[i].size(); ++j)
				if (mt[g[i][j]] == -1) {
					mt[g[i][j]] = i;
					used1[i] = true;
					break;
				}
		for (int i = 0; i<n; ++i) {
			if (used1[i])  continue;
			used.assign(n, false);
			try_kuhn(i);
		}

		int size = 0;
		for (int i = 0; i < k; ++i)
			if (mt[i] != -1)
				size++;
		int reber = n + k - size;
		int ans = tops - reber;
		
		printf("Case #%d: %d\n", tt, ans);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	solve();

	return 0;
}