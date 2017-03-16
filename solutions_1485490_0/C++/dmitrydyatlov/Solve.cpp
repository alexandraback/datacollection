#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long lint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef vector<int> vi;
typedef vector<string> vs;
const int INF = 0x7fffffff;

vector<lint> a, b, suma, sumb;
vector<int> typea, typeb;

pair<lint, lint> geta(lint x)
{
	if(x < suma[0])
		return mp(suma[0] - x, typea[0]);
	for(int i = 1; i < a.size(); ++i)
		if(x >= suma[i - 1] && x < suma[i])
			return mp(suma[i] - x, typea[i]);
}

pair<lint, lint> getb(lint x)
{
	if(x < sumb[0])
		return mp(sumb[0] - x, typeb[0]);
	for(int i = 1; i < b.size(); ++i)
		if(x >= sumb[i - 1] && x < sumb[i])
			return mp(sumb[i] - x, typeb[i]);
}

map<pll, lint> dp;
void go(lint x, lint y)
{
	if(x == suma[a.size() - 1] || y == sumb[b.size() - 1])
	{
		if(!(dp.count(mp(suma[a.size() - 1], sumb[b.size() - 1])) && dp[mp(suma[a.size() - 1], sumb[b.size() - 1])] >= dp[mp(x, y)]))
			dp[mp(suma[a.size() - 1], sumb[b.size() - 1])] = dp[mp(x, y)];
		return;
	}

	pll px = geta(x);
	pll py = getb(y);
	if(px.second == py.second)
	{
		lint mm = min(px.first, py.first);
		if(dp.count(mp(x + mm, y + mm)) && dp[mp(x + mm, y + mm)] >= dp[mp(x, y)] + mm)
			return;
		dp[mp(x + mm, y + mm)] = dp[mp(x, y)] + mm;
		go(x + mm, y + mm);
		return;
	}

	if(!(dp.count(mp(x + px.first, y)) && dp[mp(x + px.first, y)] >= dp[mp(x, y)]))
	{
		dp[mp(x + px.first, y)] = dp[mp(x, y)];
		go(x + px.first, y);
	}

	if(!(dp.count(mp(x, y + py.first)) && dp[mp(x, y + py.first)] >= dp[mp(x, y)]))
	{
		dp[mp(x, y + py.first)] = dp[mp(x, y)];
		go(x, y + py.first);
	}
}	

int Solution()
{
	dp.clear();	
	int n, m;
	cin >> n >> m;
	a.clear(); a.resize(n);
	b.clear(); b.resize(m);
	typea.clear(); typea.resize(n);
	typeb.clear(); typeb.resize(m);
	suma.clear(); suma.resize(n);
	sumb.clear(); sumb.resize(m);

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i] >> typea[i];
		if(i == 0)
			suma[0] = a[0];
		else
			suma[i] = suma[i - 1] + a[i];
	}
	for(int i = 0; i < m; ++i)
	{
		cin >> b[i] >> typeb[i];
		if(i == 0)
			sumb[0] = b[0];
		else
			sumb[i] = sumb[i - 1] + b[i];
	}

	dp[ mp(0, 0) ] = 0;
	go(0, 0);
	cout << dp[ mp(suma[n - 1], sumb[m - 1]) ];
	return 0;
}

#define debug 1

int main()
{
#ifdef debug
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cout << "Case #" << i << ": ";
		Solution();
		cout << endl;
	}
	return 0;
}
