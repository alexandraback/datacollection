#include <stdio.h>
#include <string.h>


int p[1010];


int main()
{
	int T, cas;
	int i, j, buff, ans, n, pi;
	freopen ("B-large.in", "r", stdin);
	freopen ("Blarge.txt", "w", stdout);
	scanf ("%d", &T);
	for (cas = 1; cas <= T; cas++)
	{
		ans = 1001;
		scanf ("%d", &n);
		memset (p, 0, sizeof(p));
		for (i = 0; i < n; i++)
			scanf ("%d", &pi), p[pi]++;
		for (i = 1; i <= 1000; i++)
		{
			buff = i;
			for (j = i+1; j <= 1000; j++)
			{
				if (j % i == 0)
					buff += p[j] * (j/i - 1);
				else
					buff += p[j] * (j/i);
			}
			if (buff < ans) ans = buff;
		}
		printf ("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
