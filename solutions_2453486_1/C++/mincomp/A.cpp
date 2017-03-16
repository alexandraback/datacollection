// GCJ2013.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	FILE* ifile = fopen("A-large (1).in", "r");
	FILE* ofile = fopen("a.out.txt", "w");
	fscanf(ifile, "%d", &t);
	char map[4][5];

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 4; j++)
			fscanf(ifile, "%s", map[j]);

		int winner = -1; // 0 for O, 1 or X.

		int tCount = 0;
		int oCount = 0;
		int xCount = 0;

		// Check row.
		for (int j = 0; j < 4; j++)
		{
			tCount = 0;
			oCount = 0;
			xCount = 0;
			for (int k = 0; k < 4; k++)
			{
				if (map[j][k] == 'T')
					tCount++;
				if (map[j][k] == 'O')
					oCount++;
				if (map[j][k] == 'X')
					xCount++;
			}

			if (tCount + oCount == 4)
				winner = 0;
			if (tCount + xCount == 4)
				winner = 1;
		}

		// Check column.
		for (int j = 0; j < 4; j++)
		{
			tCount = 0;
			oCount = 0;
			xCount = 0;
			for (int k = 0; k < 4; k++)
			{
				if (map[k][j] == 'T')
					tCount++;
				if (map[k][j] == 'O')
					oCount++;
				if (map[k][j] == 'X')
					xCount++;
			}

			if (tCount + oCount == 4)
				winner = 0;
			if (tCount + xCount == 4)
				winner = 1;
		}

		// Check diagonal.
		tCount = 0;
		oCount = 0;
		xCount = 0;
		for (int j = 0; j < 4; j++)
		{
			if (map[j][j] == 'T')
				tCount++;
			if (map[j][j] == 'O')
				oCount++;
			if (map[j][j] == 'X')
				xCount++;
		}
		if (tCount + oCount == 4)
			winner = 0;
		if (tCount + xCount == 4)
			winner = 1;

		tCount = 0;
		oCount = 0;
		xCount = 0;
		for (int j = 0; j < 4; j++)
		{
			if (map[j][4 - j - 1] == 'T')
				tCount++;
			if (map[j][4 - j - 1] == 'O')
				oCount++;
			if (map[j][4 - j - 1] == 'X')
				xCount++;
		}
		if (tCount + oCount == 4)
			winner = 0;
		if (tCount + xCount == 4)
			winner = 1;

		if (winner == -1)
		{
			// Check if there's empty cell.
			bool empty = false;
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
					if (map[j][k] == '.')
					{
						fprintf(ofile, "Case #%d: Game has not completed\n", i + 1);
						empty = true;
						break;
					}
				if (empty) break;
			}

			if (!empty)
				fprintf(ofile, "Case #%d: Draw\n", i + 1);
		}
		else
		{
			if (winner == 0)
				fprintf(ofile, "Case #%d: O won\n", i + 1);
			else
				fprintf(ofile, "Case #%d: X won\n", i + 1);
		}
	}
}

