#include <iostream>
using namespace std;
int f[200][200];

int g(int x, bool bSurprising)
{
	if (bSurprising)
	{
		if (x % 3 == 0)
		{
			if (x < 3)
				return -100;
			else
				return (x - 3) / 3 + 2;
		}
		else if (x % 3 == 1)
		{
			if (x < 4)
				return -100;
			else
				return (x - 4) / 3 + 2;
		}
		else if (x % 3 == 2)
		{
			if (x < 2)
				return -100;
			else
				return (x - 2) / 3 + 2;
		}
	}
	else
	{
		if (x % 3 == 0)
			return x / 3;
		else if (x % 3 == 1)
			return (x - 1) / 3 + 1;
		else if (x % 3 == 2)
			return (x - 2) / 3 + 1;
	}
}

int main () {
	int nTestCase;
	int a[200], n, s, p;

	freopen ("B-large.in", "r", stdin);
	freopen ("B-large.out", "w", stdout);

	scanf("%d", &nTestCase);
	for (int t = 0; t < nTestCase; t++)
	{
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		memset(f, 0, sizeof(f));
		for (int j = 1; j <= s; j++)
			f[0][j] = -100;

		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= s; j++)
			{
				f[i][j] = max(f[i][j], f[i - 1][j] + (g(a[i], false) >= p ? 1 : 0));
				if (j >= 1)
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + (g(a[i], true) >= p ? 1 : 0));
			}
			printf ("Case #%d: %d\n", t + 1, f[n][s]);
	}
	return 0;
}

