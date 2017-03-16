#include <cstdio>

const int N = 1010;

int a[N];
int tn, n, i;

int main()
{
	scanf("%d", &tn);

	for (int tc = 1; tc <= tn; tc++)
	{
		scanf("%d", &n);
		int m = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] > m)
				m = a[i];
		}
		int l = 1, r = m;
		while (l < r)
		{
			int t = (l + r) / 2;
			bool f = false;
			for (int spe = 0; !f && spe < t; spe++)
			{
				int fin = t - spe;
				int k = 0;
				for (i = 0; i < n; i++)
					if (a[i] > fin)
					{
						int d = a[i] / fin;
						if (a[i] % fin != 0)
							++d;
						--d;
						k += d;
					}
				if (k <= spe)
					f = true;
			}
			if (f)
				r = t;
			else
				l = t + 1;
		}
		printf("Case #%d: %d\n", tc, l);
	}

	return 0;
}