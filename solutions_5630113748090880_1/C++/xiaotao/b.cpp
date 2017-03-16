#include <cstdio>
#include <cstring>

bool flag[2501];

int main()
{
	int T, n, h;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		memset(flag, false, sizeof(flag));
		scanf("%d", &n);
		for (int i = 0; i < n * 2 - 1; ++i)
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &h);
				flag[h] = not flag[h];
			}
		printf("Case #%d:", tt);
		for (h = 1; h <= 2500; ++h)
			if (flag[h])
				printf(" %d", h);
		printf("\n");
	}
	return 0;
}
