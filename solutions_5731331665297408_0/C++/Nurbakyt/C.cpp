#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define _USE_MATH_DEFINES
#define ll long long 
#define ull unsigned long long  
#define fname ""
const int N = 123;
const double eps = 1e-6;
const ll inf = (ll)1e18 + 123;

using namespace std;

int t, n, m, a, b;
int c[N], p[N];
bool g[N][N];
string s[N], ans;

bool ok (string a, string b)
{
	for (int i = 0;i < min(sz(a), sz(b));i ++)
	{
		if (a[i] < b[i])
			return 1;
		if (a[i] > b[i])
			return 0;
	}
	if (sz(a) < sz(b))
		return 1;
	return 0;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> t;
	for (int test = 1;test <= t;test ++)
	{
		cin >> n >> m;
		memset(g, 0, sizeof g);
		for (int i = 1;i <= n;i ++)
			cin >> s[i],
			c[i] = i;
		for (int i = 1;i <= m;i ++)
		{
			cin >> a >> b;
			g[a][b] = g[b][a] = 1;
		}
		ans = "";
		do
		{
			string cur = "";
			for (int i = 1;i <= n;i ++)
				cur += s[c[i]];
			if (ans != "" && !ok(cur, ans))
				continue;
			p[c[1]] = -1;
			int now = c[1];
			for (int i = 2;i <= n;i ++)
			{
				while(1)
				{
					if (g[now][c[i]])
					{
						p[c[i]] = now;
						now = c[i];
						break;
					}
					now = p[now];
					if (now == -1)
						goto qwe;
				}
			}
			ans = cur;
			qwe:;
		}
		while(next_permutation(c + 1, c + n + 1));
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}
