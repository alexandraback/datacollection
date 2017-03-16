#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int isWinningLine(char line[4])
{
	bool hasX = false, hasO = false;
	for (int i = 0; i < 4; ++i)
	{
		if (line[i] == '.')
			return 0;
		hasX |= (line[i] == 'X');
		hasO |= (line[i] == 'O');
	}
	if (hasX && hasO)
	{
		return 0;
	}
	return hasX ? 1 : 2;
}

int winningRow(char board[4][4], int row)
{
	char line[4];
	for (int i = 0; i < 4; ++i)
		line[i] = board[row][i];
	return isWinningLine(line);
}

int winningColumn(char board[4][4], int column)
{
	char line[4];
	for (int i = 0; i < 4; ++i)
		line[i] = board[i][column];
	return isWinningLine(line);
}

int winningDiagonal(char board[4][4])
{
	char line[4];
	for (int i = 0; i < 4; ++i)
		line[i] = board[i][i];
	int mainDiagonalWinner = isWinningLine(line);

	for (int i = 0; i < 4; ++i)
		line[i] = board[i][3 - i];
	int sideDiagonalWinner = isWinningLine(line);

	return mainDiagonalWinner ? mainDiagonalWinner : sideDiagonalWinner;
}

string solveTest()
{
	char board[4][4];
	bool notFull = false;
	for (int h = 0; h < 4; ++h)
	{
		for (int w = 0; w < 4; ++w)
		{
			scanf("%c", &board[h][w]);
			if (board[h][w] == '.')
			{
				notFull = true;
			}
		}
		scanf("\n");
	}
	scanf("\n");

	for (int i = 0; i < 4; ++i)
	{
		size_t winner = winningColumn(board, i);		
		if (!winner)
			winner = winningRow(board, i);
		if (!winner)
			winner = winningDiagonal(board);

		if (winner)
		{
			return (winner == 1) ? "X won" : "O won";
		}
	}
	if (notFull)
	{
		return "Game has not completed";
	}
	return "Draw";
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	size_t T;
	scanf("%d\n", &T);
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		string verdict = solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
