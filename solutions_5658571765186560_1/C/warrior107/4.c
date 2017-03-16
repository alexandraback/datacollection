#include<stdio.h>

int main()
{
	int t;
	int i;
	int x, r, c;

	scanf("%d", &t);

	for (i = 1; i <= t; i++)
	{
		scanf("%d %d %d", &x, &r, &c);

		if (x >= 7)
		{
			printf("Case #%d: RICHARD\n", i);
			continue;
		}
		if ((r*c) % x != 0)
		{
			printf("Case #%d: RICHARD\n", i);
			continue;
		}
		if (((x + 1) / 2) > c || ((x + 1) / 2) > r)
		{
			printf("Case #%d: RICHARD\n", i);
			continue;
		}
		if (x > c && x > r)
		{
			printf("Case #%d: RICHARD\n", i);
			continue;
		}
		if (x == 4)
		{
			if (r == 2 || c == 2)
			{
				printf("Case #%d: RICHARD\n", i);
				continue;
			}
		}
		if (x == 5)
		{
			if ((c == 3 && r == 5) || (c == 5 && r == 3))
			{
				printf("Case #%d: RICHARD\n", i);
				continue;
			}
		}
		if (x == 6)
		{
			if (r == 3 || c == 3)
			{
				printf("Case #%d: RICHARD\n", i);
				continue;
			}
		}

		printf("Case #%d: GABRIEL\n", i);
	}

	return 0;
}