#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#define rep(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

int n, cur, a[1009], vis[1009];
vector <int> s[1009];

void dfs (int x, int num)
{
	//printf ("%d %d dfs\n", x, num);
	//system ("pause");
	if (s[x].size () == 0)
	{
		cur = max (cur, num);
		return;
	}
	rep (i, 0, s[x].size () - 1)
		if (!vis[s[x][i]])
			dfs (s[x][i], num + 1);
	return;
}

int find (int x)
{
	cur = 1;
	rep (i, 0, s[x].size () - 1)
		if (!vis[s[x][i]])
			dfs (s[x][i], 2);
	return cur - 1;
}


int count (int x)
{
	memset (vis, 0, sizeof (vis));
	int ret = 1, now = x;
	vis[x] = 1;
	while (1)
	{
		if (!vis[a[now]])
			now = a[now], vis[now] = 1, ret++;
		else
			/*if (a[a[now]] == now)
			{
			//	printf ("%d find   %d\n", x, now);
				return ret + find (now);
			}
			else
				if (a[now] == x)*/
					return ret;
	}
}

int main ()
{
	freopen ("3.in", "r", stdin); freopen ("3.out", "w",stdout);
	int ti;
	cin >> ti;
	rep (cnt, 1, ti)
	{
		cin >> n;
		int ans = 0;
		rep (i, 1, n)
			s[i].clear();
		rep (i, 1, n)
			scanf ("%d", &a[i]), s[a[i]].push_back(i);
		rep (i, 1, n)
			ans = max (ans, count (i));//, printf ("%d %d\n", i, count (i));
		memset (vis, 0, sizeof (vis));
		rep (i, 1, n)
			rep (j, i + 1, n)
				if (a[i] == j && a[j] == i)
				{
					vis[i] = vis[j] = 1;
					ans = max (ans, find (i) + find (j) + 2);
					vis[i] = vis[j] = 0;
				}
		printf ("Case #%d: %d\n", cnt, ans);
	}
	return 0;
}
