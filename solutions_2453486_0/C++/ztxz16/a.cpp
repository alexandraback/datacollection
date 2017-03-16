#include <stdio.h>
#include <stdlib.h>

int test, tt, i, j, tx, ty, owin, xwin, tag;
char map[16][16], c;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	while (test > 0)
	{
		test--;
		tt++;
		printf("Case #%d: ", tt);
		tx = ty = 0;
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
			{
				scanf("%c", &c);
				if (c == '.' || c == 'T' || c == 'X' || c == 'O')
				{
					map[i][j] = c;
					if (c == 'T')
						tx = i, ty = j;
				}
				
				else
					j--;
			}
		
		owin = xwin = tag = 0;
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++)
				if (map[i][j] == '.')
					tag = 1;
		map[tx][ty] = 'O';
		for (i = 1; i <= 4; i++)
		{
			if (map[i][1] == 'O' && map[i][2] == 'O' && map[i][3] == 'O' && map[i][4] == 'O')
				owin = 1;
			if (map[1][i] == 'O' && map[2][i] == 'O' && map[3][i] == 'O' && map[4][i] == 'O')
				owin = 1;
		}
		
		if (map[1][1] == 'O' && map[2][2] == 'O' && map[3][3] == 'O' && map[4][4] == 'O')
			owin = 1;
		if (map[1][4] == 'O' && map[2][3] == 'O' && map[3][2] == 'O' && map[4][1] == 'O')
			owin = 1;
		
		map[tx][ty] = 'X';
		for (i = 1; i <= 4; i++)
		{
			if (map[i][1] == 'X' && map[i][2] == 'X' && map[i][3] == 'X' && map[i][4] == 'X')
				xwin = 1;
			if (map[1][i] == 'X' && map[2][i] == 'X' && map[3][i] == 'X' && map[4][i] == 'X')
				xwin = 1;
		}
		
		if (map[1][1] == 'X' && map[2][2] == 'X' && map[3][3] == 'X' && map[4][4] == 'X')
			xwin = 1;
		if (map[1][4] == 'X' && map[2][3] == 'X' && map[3][2] == 'X' && map[4][1] == 'X')
			xwin = 1;
		
		if (owin == 1)
			printf("O won\n");
		else if (xwin == 1)
			printf("X won\n");
		else if (tag == 1)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	
	return 0;
}
