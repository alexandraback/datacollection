#include <stdio.h>

int grid[110][110];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("q2out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		int n,m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &grid[i][j]);
			}
		}
		bool atLeast1 = true;
		while (atLeast1)
		{
			int mx = 0, my = 0, M = 10000;
			atLeast1 = false;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (grid[i][j] != 0 && grid[i][j] < M)
					{
						M = grid[i][j];
						my = i; mx = j;
						atLeast1 = true;
					}
					else if (grid[i][j] != 0) atLeast1 = true;
				}
			}
			//printf("min = %d at (%d,%d)\n", M,mx,my);
			if (!atLeast1)
			{
				printf("YES\n");
				break;
			}
			bool bad = false;
			for (int i = 0; i < n; i++)
			{
				if (grid[i][mx] && grid[i][mx] != M)
				{
					bad = true;
					break;
				}
			}
			if (!bad)
			{
				for (int i = 0; i < n; i++) grid[i][mx] = 0;
				//printf("changing col %d\n", mx);
				continue;
			}
			bool bad2 = false;
			for (int j = 0; j < m; j++)
			{
				if (grid[my][j] && grid[my][j] != M)
				{
					bad2 = true;
					break;
				}
			}
			if (!bad2)
			{
				for (int j = 0; j < m; j++) grid[my][j] = 0;
				//printf("changing row %d\n", my);
			}
			if (bad && bad2)
			{
				printf("NO\n");
				break;
			}
			/*
			printf("GRID:\n");
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					printf("%d ",grid[i][j]);
				}printf("\n");
			}*/
			//printf(".");
		}
	}
}