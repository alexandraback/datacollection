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
		if (x <= 3)
		{
			printf("Case #%d: GABRIEL\n", i);
			continue;
		}
		else
		{
			if (r == 2 || c == 2)
			{
				printf("Case #%d: RICHARD\n", i);
				continue;
			}
			printf("Case #%d: GABRIEL\n", i);
			continue;
		}

	}

	return 0;
}