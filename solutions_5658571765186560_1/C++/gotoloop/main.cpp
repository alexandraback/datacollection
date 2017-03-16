#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool ok(int sx, int sy, int nx, int ny)
{
	return (nx <= sx && ny <= sy) || (ny <= sx && nx <= sy);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		int x, r, c;
		scanf("%d%d%d", &x, &r, &c);
		if (x >= 7)
		{
			printf("Case #%d: RICHARD\n", k + 1);
		}
		else
		{
			if (r * c % x != 0)
			{
				printf("Case #%d: RICHARD\n", k + 1);
			}
			else
			{
				switch (x)
				{
				case 1:
					printf("Case #%d: GABRIEL\n", k + 1);
					break;
				case 2:
					printf("Case #%d: GABRIEL\n", k + 1);
					break;
				case 3:
					if (r % 3 == 0)
					{
						if (c >= 2)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					else
					{
						if (r >= 2)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					break;
				case 4:
					if (r % 4 == 0)
					{
						if (c >= 3)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					else if (c % 4 == 0)
					{
						if (r >= 3)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					else
					{
						if (ok(r, c, 3, 4))
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					break;
				case 5:
					if (r % 5 == 0)
					{
						if (c >= 4)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					else
					{
						if (r >= 4)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					break;
				case 6:
					if (r % 6 == 0)
					{
						if (c >= 4)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					else if (c % 6 == 0)
					{
						if (r >= 4)
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					else
					{
						if (ok(r, c, 4, 6))
						{
							printf("Case #%d: GABRIEL\n", k + 1);
						}
						else
						{
							printf("Case #%d: RICHARD\n", k + 1);
						}
					}
					break;
				}
			}
		}
	}
}