#include <stdio.h>
#include <iostream>

using namespace std;

FILE *inputFile, *outputFile;
int r, c, m;
int **board;

int freeSpace;
int leftSide;
int rightSide;
int leftCounter;
int rightCounter;

bool writeBoard(int testCase)
{
	fprintf(outputFile, "Case #%d:\n", testCase+1);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if ((i == 0) && (j == 0))
			{
				fprintf(outputFile, "c");
			}
			else
			{
				if (board[i][j] == 0)
					fprintf(outputFile, ".");
				else
					fprintf(outputFile, "*");
			}
		}
		fprintf(outputFile, "\n");
	}
}

bool specialCaseOneRow()
{
	if (m < c)
	{
		for (int i = 0; i < c-m; i++)
		{
			board[0][i] = 0;
		}
		for (int i = c-m; i < c; i++)
		{
			board[0][i] = 1;
		}

		return true;
	}
	else
		return false;
}

bool specialCaseOneColumn()
{
	if (m < r)
	{
		for (int i = 0; i < r-m; i++)
		{
			board[i][0] = 0;
		}
		for (int i = r-m; i < r; i++)
		{
			board[i][0] = 1;
		}

		return true;
	}
	else
		return false;
}

bool specialCaseTwoRow()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			board[i][j] = 1;

	int freeSpace = r * c - m;

	if (freeSpace == 1)
	{
		board[0][0] = 0;
		return true;
	}
	else if ((freeSpace == 2 ) || (freeSpace == 3))
	{
		return false;
	}
	else if (freeSpace % 2 == 0)
	{
		for (int i = 0; i < freeSpace / 2; i++)
		{
			board[0][i] = 0;
			board[1][i] = 0;
		}
	}
	else
		return false;
}

bool specialCaseTwoColumn()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			board[i][j] = 1;

	int freeSpace = r * c - m;

	if (freeSpace == 1)
	{
		board[0][0] = 0;
		return true;
	}
	else if ((freeSpace == 2 ) || (freeSpace == 3))
	{
		return false;
	}
	else if (freeSpace % 2 == 0)
	{
		for (int i = 0; i < freeSpace / 2; i++)
		{
			board[i][0] = 0;
			board[i][1] = 0;
		}
	}
	else
		return false;
}

int checkBoard()
{
	if (freeSpace == 0) return 1;

	if (freeSpace < -1) return -1;

	if (freeSpace == -1)
	{
		if (leftSide < r)
		{
			int right = rightSide-1 < c ? rightSide-1 : c-1;
			if ((board[leftSide-1][right] == 0) && (((leftSide < r) && (board[leftSide][right] == 1)) || (leftSide >= r)))
			{
				board[leftSide-1][right] = 1;
				return 1;
			}
			return -1;
		}
		else
		{
			if ((board[r-1][rightSide-1] == 0) && (((rightSide < c) && (board[r-1][rightSide] == 1)) || (rightSide >= c)))
			{
				board[r-1][rightSide-1] = 1;
				return 1;
			}
			return -1;
		}
	}

	return 0;
}

bool generalInflate()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			board[i][j] = 1;

	freeSpace = r * c - m;

	if (freeSpace == 0)
		return false;
	else if (freeSpace == 1)
	{
		board[0][0] = 0;
		return true;
	}
	else if ((freeSpace == 2) || (freeSpace == 3))
		return false;
	else
	{
		leftSide = 2;
		rightSide = 2;
		leftCounter = 0;
		rightCounter = 0;

		board[0][0] = 0;
		board[0][1] = 0;
		board[1][0] = 0;
		board[1][1] = 0;

		freeSpace -= 4;

		while (freeSpace != 0)
		{
			if (leftSide < r)
			{
				board[leftSide][0] = 0;
				board[leftSide][1] = 0;
				freeSpace -= 2;
			}
			switch (checkBoard()) { case -1: return false; break; case 1: return true; break; }

			if (rightSide < c)
			{
				board[0][rightSide] = 0;
				board[1][rightSide] = 0;
				freeSpace -= 2;
			}
			switch (checkBoard()) { case -1: return false; break; case 1: return true; break; }

			if (leftSide < r)
			{
				int rightSideToGo = rightSide < c ? leftSide : c;
				for (int i = 2; i < rightSideToGo; i++)
				{
					if ((i < c) && (board[leftSide][i] == 1))
					{
						board[leftSide][i] = 0;
						freeSpace--;
					}
					switch (checkBoard()) { case -1: return false; break; case 1: return true; break; }
				}
			}

			if (rightSide < c)
			{
				int bottomSideToGo = leftSide < r ? rightSide + 1 : r;
				for (int i = 2; i < bottomSideToGo; i++)
				{
					if ((i < r) && (board[i][rightSide] == 1))
					{
						board[i][rightSide] = 0;
						freeSpace--;
					}
					switch (checkBoard()) { case -1: return false; break; case 1: return true; break; }
				}
			}

			leftSide++;
			rightSide++;
		}

		return (freeSpace == 0);
	}
}

int main(int argc,char *argv[])
{
	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w");

	int t;
	fscanf(inputFile, "%d", &t);

	for (int i = 0; i < t; i++)
	{
		fscanf(inputFile, "%d %d %d", &r, &c, &m);

		board = new int*[r];
		for (int j = 0; j < r; j++)
			board[j] = new int[c];

		bool result;

		if (r == 1)
			result = specialCaseOneRow();
		else if (c == 1)
			result = specialCaseOneColumn();
		else if (r == 2)
			result = specialCaseTwoRow();
		else if (c == 2)
			result = specialCaseTwoColumn();
		else 
			result = generalInflate();

		if (result)
			writeBoard(i);
		else
			fprintf(outputFile, "Case #%d:\nImpossible\n", i+1);

		for (int j = 0; j < r; j++)
			delete [] board[j];
		delete [] board;		
	}

	fclose(inputFile);
	fclose(outputFile);
}