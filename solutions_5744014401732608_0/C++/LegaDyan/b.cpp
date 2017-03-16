#include <iostream>
#include <cstring>
#include <queue>
#include <cstring>
#include <algorithm>
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define ll long long
#define intt long long

using namespace std;

ll n, m, f[10009];
int a[59][59];

int main ()
{
	//freopen ("2.in", "r", stdin);freopen ("2.out", "w", stdout);
	f[2] = 1;
	rep (i, 3, 50)
		f[i] = 2 * f[i - 1];
	//rep (i, 2, 50) cout << i << ' ' << f[i] << endl;
	int ti;
	cin >> ti;
	rep (ff, 1, ti)
	{
		memset (a, 0, sizeof (a));
		printf ("Case #%d: ", ff);
		cin >> n >> m;
		if (m > (1 << (n -  2)))
		{
			printf ("IMPOSSIBLE\n");
			continue;
		}
		/*if (m == (1 << (n - 2)))
		{
			printf ("POSSIBLE\n");
			for (int i = 1; i <= n - 1; i++, printf ("\n"))
				rep (j, 1, n)
					printf ("1");
			rep (i, 1, n - 1)
				printf ("0");
			printf ("1\n");
			continue;
		}*/
		rep (i, 1, n - 1)
			rep (j, i + 1, n - 1)
				a[i][j] = 1;
		//for (int i = 1; i <= n; i++, printf ("\n")) rep (j, 1, n) printf ("%d", a[i][j]);
		intt k = 50;
		if (m == (1 << (n - 2)))
			rep (i, 1, n - 1)
				a[i][n] = 1;
		while (m > 0)
		{
			while (f[k] > m)
				k--;
			//printf ("k %d\n", k);
			m -= f[k];
			if (k < n)
				a[k][n] = 1;
		}
		printf ("POSSIBLE\n");
		for (int i = 1; i <= n; i++, printf ("\n"))
			rep (j, 1, n)
				printf ("%d", a[i][j]);
	}
	return 0;
}
