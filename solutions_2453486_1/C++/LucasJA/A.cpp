#include <cstdio>

char m[4][4];

int main()
{
	int t;
	scanf("%d", &t);
	
	for (int k = 0; k < t; ++k)
	{
		bool dot = false;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
			{
				scanf(" %c ", &m[i][j]);
				dot = dot || m[i][j] == '.';
			}
		
		bool xWin = false;
		bool oWin = false;
				
		for (int i = 0; i < 4; ++i)
		{
			int x = 0;
			int o = 0;
			for (int j = 0; j < 4; ++j)
			{
				x += m[i][j] == 'X' || m[i][j] == 'T' ? 1 : 0;
				o += m[i][j] == 'O' || m[i][j] == 'T' ? 1 : 0;
			}
			xWin = xWin || x == 4;
			oWin = oWin || o == 4;
		}
		for (int j = 0; j < 4; ++j)
		{
			int x = 0;
			int o = 0;
			for (int i = 0; i < 4; ++i)
			{
				x += m[i][j] == 'X' || m[i][j] == 'T' ? 1 : 0;
				o += m[i][j] == 'O' || m[i][j] == 'T' ? 1 : 0;
			}
			xWin = xWin || x == 4;
			oWin = oWin || o == 4;
		}
		int x = 0;
		int o = 0;
		for (int ij = 0; ij < 4; ++ij)
		{
			x += m[ij][ij] == 'X' || m[ij][ij] == 'T' ? 1 : 0;
			o += m[ij][ij] == 'O' || m[ij][ij] == 'T' ? 1 : 0;
		}
		xWin = xWin || x == 4;
		oWin = oWin || o == 4;
		x = 0;
		o = 0;
		for (int ij = 0; ij < 4; ++ij)
		{
			x += m[ij][3 - ij] == 'X' || m[ij][3 - ij] == 'T' ? 1 : 0;
			o += m[ij][3 - ij] == 'O' || m[ij][3 - ij] == 'T' ? 1 : 0;
		}
		xWin = xWin || x == 4;
		oWin = oWin || o == 4;
		
		printf("Case #%d: ", k + 1);
		if (xWin)
			printf("X won\n");
		else if (oWin)
			printf("O won\n");
		else if (!dot)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	
	return 0;
}
