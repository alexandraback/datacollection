#include "common.h"

bool Same(char c1, char c2, char c3, char c4, char &outWinner)
{
	if (c1 == 'T') 
	{
		if (c2 == '.')
			return false;
		outWinner = c2;
		return c2 == c3 && c2 == c4;
	}
	else if (c1 == '.')
	{
		return false;
	} 
	else
	{
		outWinner = c1;
		return (c1 == c2 || c2 =='T') && 
			(c1 == c3 || c3 == 'T') && 
			(c1 == c4 || c4 == 'T');
	}
}

void SovleA(char * input)
{
	INT ln;
	READ(ln), NL;
	for (INT i = 0; i < ln; i++)
	{
		char f[4][4];
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				READ(f[x][y]);
			}
			NL;
		}
		NL;
		char winner;
		bool gotWinner = Same(f[0][0], f[1][1], f[2][2], f[3][3], winner) ||
							Same(f[3][0], f[2][1], f[1][2], f[0][3], winner);
		bool gameOver = true;
		for (int j = 0; !gotWinner && j < 4; j++)
		{
			if (Same(f[j][0], f[j][1], f[j][2], f[j][3], winner) ||
				Same(f[0][j], f[1][j], f[2][j], f[3][j], winner))
			{
				gotWinner = true;
			}
			if (f[j][0] == '.' || f[j][1] == '.' || f[j][2] == '.' || f[j][3] == '.')
				gameOver = false;
		}
		if (gotWinner)
		{
			fprintf(stdout, "Case #%I64d: %c won\n", i + 1, winner);
		}
		else
		{
			if (gameOver)
			{
				fprintf(stdout, "Case #%I64d: Draw\n", i + 1);
			}
			else
			{
				fprintf(stdout, "Case #%I64d: Game has not completed\n", i + 1);
			}
		}
	}
//	fprintf(stderr, input);
//	fprintf(stdout, "OK!");
}