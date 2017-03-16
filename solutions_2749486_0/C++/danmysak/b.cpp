#include <stdio.h>

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int test = 0; test < t; test++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", test + 1);

		while (x > 0)
		{
			printf("WE");
			x--;
		}

		while (x < 0)
		{
			printf("EW");
			x++;
		}

		while (y > 0)
		{
			printf("SN");
			y--;
		}

		while (y < 0)
		{
			printf("NS");
			y++;
		}

		printf("\n");
	}

	return 0;
}