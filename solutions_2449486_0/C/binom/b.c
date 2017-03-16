#include <stdio.h>

int field[100][100];

int maxr[100], maxc[100];

int main()
{
	int t, n, m, k, i, j;
	scanf("%d\n", &t);
	for(k = 0; k < t; k++)
	{
		scanf("%d %d", &n, &m);
		for(i = 0; i < 100; i++)
		{
			maxr[i] = 0;
			maxc[i] = 0;
		}
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				scanf("%d", &field[j][i]);
				if(field[j][i] > maxc[j])
				{
					maxc[j] = field[j][i];
				}
				if(field[j][i] > maxr[i])
				{
					maxr[i] = field[j][i];
				}
			}
		}
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(field[j][i] != maxc[j] && field[j][i] != maxr[i])
				{
					break;
				}
			}
			if(j != m) break;
		}
		printf("Case #%d: %s\n", k + 1, (i == n) ? "YES" : "NO");
	}
	return 0;
}
