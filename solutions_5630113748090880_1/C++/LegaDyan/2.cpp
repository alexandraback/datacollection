#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#define rep(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

int n, vis[2900];

int main ()
{
	freopen ("2.in","r", stdin);freopen ("2.out", "w", stdout);
	int ti;
	cin >> ti;
	rep (cnt, 1, ti)
	{
		memset (vis, 0, sizeof (vis));
		cin >> n;
		int x0;
		rep (i, 1, 2 * n - 1)
			rep (j, 1, n)
				scanf ("%d", &x0), vis[x0]++;
		printf ("Case #%d:", cnt);
		rep (i, 1, 2500)
			if (vis[i] % 2)
			{
				printf (" %d", i);
			}
		printf ("\n");
	}
	return 0;
}
