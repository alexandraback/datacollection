#include <stdio.h>

int main()
{
	int t;
	char map[103][103];
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int m, n;
		bool flag = true;
		scanf("%d%d", &m, &n);
		for (int j = 1; j <= m; ++j)
		{
			map[j][0] = 0;
			for (int k = 1; k <= n; ++k)
			{
				scanf("%d", &map[j][k]);
				if (map[j][k] > map[j][0])
					map[j][0] = map[j][k];
			}
		}
		for (int k = 1; k <= n; ++k)
		{
			map[0][k] = 0;
			for (int j = 1; j <= m; ++j)
			{
				if (map[j][k] > map[0][k])
					map[0][k] = map[j][k];
			}
		}
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				if (map[j][k] < map[j][0] && map[j][k] < map[0][k])
				{
					flag = false;
					goto end;
				}
			}
		}
end:
		printf("Case #%d: %s\n", i, flag ? "YES" : "NO");
	}
}