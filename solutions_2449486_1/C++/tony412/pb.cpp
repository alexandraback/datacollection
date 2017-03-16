#include <stdio.h>
#include <algorithm>
#define INF 200

int map[105][105];

int main()
{
	int t, c;
	int n, m, i, j, flag;
	int maxr[105], maxc[105];

	scanf("%d", &t);
	for (c = 1; c <= t; c++)
	{
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &map[i][j]);

		for (i = 0; i < n; i++)
		{
			maxr[i] = 0;
			for (j = 0; j < m; j++)
				maxr[i] = std::max(maxr[i], map[i][j]);
		}
		for (i = 0; i < m; i++)
		{
			maxc[i] = 0;
			for (j = 0; j < n; j++)
				maxc[i] = std::max(maxc[i], map[j][i]);
		}

		flag = 1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				if (maxr[i] > map[i][j] && maxc[j] > map[i][j])
				{
					flag = 0;
					break;
				}
			if (!flag) break;
		}
		printf("Case #%d: %s\n", c, flag ? "YES" : "NO");
	}	
	return 0;
}
