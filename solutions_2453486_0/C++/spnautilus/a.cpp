#include <stdio.h>

#define MAXN (8)

char B[MAXN][MAXN];
int T;

int check(int r, int c, int dr, int dc)
{
	int i;
	int X = 0;
	int O = 0;

	for(i = 0; i < 4; ++i)
	{
		if(B[r][c] == 'X')
			++X;
		else if(B[r][c] == 'O')
			++O;
		else if(B[r][c] == 'T')
		{
			++X;
			++O;
		}

		r += dr;
		c += dc;
	}

	if(X == 4)
		return 1;
	if(O == 4)
		return -1;
	return 0;
}

int main()
{
	int tt;
	scanf("%d", &T);
	for(tt = 1; tt <= T; ++tt)
	{
		int i, j;
		for(i = 0; i < 4; ++i)
			scanf("%s", B[i]);

		int sum = 0;

		for(i = 0; i < 4; ++i)
		{
			sum += check(i, 0, 0, 1);
			sum += check(0, i, 1, 0);
		}
		sum += check(0, 0, 1, 1);
		sum += check(3, 0, -1, 1);

		printf("Case #%d: ", tt);

		if(sum > 0)
			printf("X won\n");
		else if(sum < 0)
			printf("O won\n");
		else
		{
			int dot = 0;
			for(i = 0; i < 4; ++i)
			{
				for(j = 0; j < 4; ++j)
				{
					dot += (B[i][j] == '.');
				}
			}

			if(dot)
				printf("Game has not completed\n");
			else
				printf("Draw\n");
		}
	}

	return 0;
}
