#include <stdio.h>

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, x, y;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		printf("Case #%d: ", cas);
		scanf("%d%d", &x, &y);
		if (x > 0)
		{
			while (x--)
			{
				printf("WE");
			}
		}
		else
		{
			x = -x;
			while (x--)
			{
				printf("EW");
			}
		}
		if (y > 0)
		{
			while (y--)
			{
				printf("SN");
			}
		}
		else
		{
			y = -y;
			while (y--)
			{
				printf("NS");
			}
		}
		puts("");
	}
	return 0;
}