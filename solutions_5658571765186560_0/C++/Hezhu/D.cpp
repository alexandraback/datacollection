#include <cstdio>

const char win[] = "Case #%d: GABRIEL\n";
const char lose[] = "Case #%d: RICHARD\n";

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int X, R, C;
		scanf("%d %d %d", &X, &R, &C);
		if (X == 1)
		{
			printf(win, kase);
		}
		else if (X == 2)
		{
			if (R * C % 2 == 0)
			{
				printf(win, kase);
			}
			else
			{
				printf(lose, kase);
			}
		}
		else if (X >= 7)
		{
			printf(lose, kase);
		}
		else if (R * C % X > 0)
		{
			printf(lose, kase);
		}
		else if (X == 3)
		{
			if ((R > 1 && C % 3 == 0) || (C > 1 && R % 3 == 0))
			{
				printf(win, kase);
			}
			else
			{
				printf(lose, kase);
			}
		}
		else if (X == 4)
		{
			if ((R % 4 == 0 && C > 2) || (R > 2 && C % 4 == 0))
			{
				printf(win, kase);
			}
			else
			{
				printf(lose, kase);
			}
		}
	}
	return 0;
}
