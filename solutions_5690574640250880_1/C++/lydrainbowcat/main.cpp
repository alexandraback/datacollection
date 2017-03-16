#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T, n, m, t, Case = 0;
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> t;
		printf("Case #%d:\n", ++Case);
		if (t == n*m - 1)
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					putchar('*');
				}
				puts("");
			}
			for (int j = 1; j < m; j++)
			{
				putchar('*');
			}
			puts("c");
			continue;
		}
		if (n == 1 && t != m)
		{
			for (int i = 1; i < m; i++)
			{
				if (i <= t) putchar('*'); else putchar('.');
			}
			puts("c");
			continue;
		}
		if (m == 1 && t != n)
		{
			for (int i = 1; i < n; i++)
			{
				if (i <= t) puts("*"); else puts(".");
			}
			puts("c");
			continue;
		}
		int r;
		for (r = 0; r < n - 1; r++)
		{
			for (int c = 0; c < m - 1; c++)
			{
				int i = n - r, j = m - c;
				if (n*m - i*j <= t&&t <= n*m - i*j + (i - 2)*(j - 2))
				{
					t -= n*m - i*j;
					int k = (j == 2 ? 0 : t / (j - 2));
					for (int l = 1; l <= r; l++)
					{
						for (int p = 1; p <= m; p++)
						{
							putchar('*');
						}
						puts("");
					}
					for (int l = 1; l <= k; l++)
					{
						for (int p = 1; p <= m - 2; p++)
						{
							putchar('*');
						}
						puts("..");
					}
					int q = (j == 2 ? 0 : t % (j - 2));
					for (int p = 1; p <= m; p++)
					{
						if (p <= c + q) putchar('*'); else putchar('.');
					}
					puts("");
					for (int l = r + k + 2; l <= n; l++)
					{
						for (int p = 1; p <= m; p++)
						{
							if (l == n&&p == m) putchar('c');
							else if (p <= c) putchar('*'); else putchar('.');
						}
						puts("");
					}
					r = n; c = m; break;
				}
			}
		}
		if (r == n - 1) puts("Impossible");
	}
}