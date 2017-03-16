#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <cstdio>
#include <list>

using namespace std;

#define rs resize
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
#define ms(a, x) memset((a), (x), sizeof(a))
#define ass assign
#define inf (int)1e9
#define pi 3.1415926535
#define reverse(a) reverse((a).begin(),(a).end())
#define sort(a) sort((a).begin(),(a).end())
#define sf scanf
#define pf printf

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vvl> vvvl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef set <int> si;
typedef queue <int> qi;
typedef vector <string> vs;
typedef vector <bool> vb;
typedef unsigned long long ull;
typedef vector <vb> vvb;

const ll M = 1e9 + 7;

ll f(ll x)
{
	if (x <= 1)
		return 1;
	return (f(x - 1) * x) % M;
}

void solve()
{
	int n;
	cin >> n;
	vs a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vi type(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < sz(a[i]); ++j)
			if (a[i][j] != a[i][0])
				type[i] = 1;
	for (int i = 0; i < n; ++i)
	{
		if (type[i] == 0)
			continue;
		for (int j = 0; j < sz(a[i]); ++j)
			if (a[i][j] != a[i][0] && a[i][j] != a[i].back())
				type[i] = 2;
	}
	
	bool u[26];
	ms(u, 0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < sz(a[i]); ++j)
		{
			if (a[i][j] != a[i][0] && a[i][j] != a[i].back())
			{
				if (u[a[i][j] - 'a'])
				{
					cout << 0 << endl;
					return ;
				}
				else
				{
					char x = a[i][j];
					u[x - 'a'] = 1;
					while (a[i][j] == x)
						j++;
					j--;
				}
			}
		}
	for (int i = 0; i < n; ++i)
		if (u[a[i][0] - 'a'] || u[a[i].back() - 'a'])
		{
			cout << 0 << endl;
			return ;
		}
	vs b(n, "");
	for (int i = 0; i < n; ++i)
		if (type[i] == 0)
			b[i] += a[i][0];
		else
		{
			b[i] += a[i][0];
			b[i] += a[i].back();
		}
	vvi g(26), g1(26);
	int c[26];
	ms(c, 0);
	for (int i = 0; i < n; ++i)
		if (sz(b[i]) == 1)
			c[b[i][0] - 'a']++;
		else
		{
			g[b[i][0] - 'a'].pb(b[i][1] - 'a');
			g1[b[i][1] - 'a'].pb(b[i][0] - 'a');
		}
	ms(u, 0);
	ll ans = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (sz(g1[i]) != 0)
			continue;
		int x = i, l = 1;
		u[x] = 1;
		while (1)
		{
			if (sz(g[x]) == 0)
				break;
			if (sz(g[x]) > 1 || u[g[x][0]])
			{
				cout << 0 << endl;
				return ;
			}
			x = g[x][0];
			u[x] = 1;
			l++;
		}
		ans++;
	}
	for (int i = 0; i < 26; ++i)
		if (!u[i] && (sz(g[i]) != 0 || sz(g1[i]) != 0))
		{
			cout << 0 << endl;
			return ;
		}
	for (int i = 0; i < 26; ++i)
		if (c[i] == 0 && sz(g[i]) == 0 && sz(g1[i]) == 0)
			ans--;
	ans = f(ans);
	for (int i = 0; i < 26; ++i)
		ans = (ans * f(c[i])) % M;
	cout << ans << endl;
	return ;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
}