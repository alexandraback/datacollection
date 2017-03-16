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
const int N = (int)1e6 + 123;
const double eps = 1e-6;
const ll inf = (ll)1e18 + 123;

using namespace std;

int t, n, ans;
string s, a[123], cur;
int b[123];
bool u[30], c[30];

bool check(string a)
{
	bool ok = 1;
	memset(u, 0, sizeof u);
	for (int i = 0;i < sz(a);i ++)
	{
		if (i != 0 && a[i] == a[i - 1])
			continue;
		if (u[a[i] - 'a'])
		{
			ok = 0;
			break;
		}
		u[a[i] - 'a'] = 1;
	}
	if (ok)				
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
		cin >> n;
		ans = 0;
		memset(c, 0, sizeof c);
		for (int i = 1;i <= n;i ++)
		{
			cin >> s;
			b[i] = i;
			a[i] = s[0];
			for (int j = 1;j < sz(s);j ++)
				if (s[j] != s[j - 1])
					a[i] += s[j];					
			if (!check(a[i]))
				goto qwe;
			for (int j = 0;j < sz(a[i]);j ++)
			{
				if (c[a[i][j] - 'a'])
					goto qwe;
				if (j != 0 && j + 1 != sz(a[i]))
					c[a[i][j] - 'a'] = 1;
			}
		}
		do
		{
			cur = "";
			for (int i = 1;i <= n;i ++)
				cur += a[b[i]];
			if (check(cur))
				ans ++;
		}
		while(next_permutation(b + 1, b + n + 1));
		qwe:;
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}
