#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>

#define MAX_STR_NUM 256

int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "A-small-attempt0.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T, board[4][4];
	fscanf(input, "%d\n", &T);
	for(int i = 1; i <= T; ++i)
	{
		bool hasEmpty = false;
		char ch;
		for (int r = 0; r < 4; ++r)
		{
			for (int c = 0; c < 4; ++c)
			{
				fscanf(input, "%c", &ch);
				board[r][c] = ch;
				hasEmpty = hasEmpty || (ch == '.');
				//printf("%c", ch);
			}
			fscanf(input, "\n");
			//printf("\n");
		}
		fscanf(input, "\n");
		//printf("\n");
		bool xW = false;
		bool oW = false;
		for (int r = 0; !xW && !oW && r < 4; ++r)
		{
			xW =	(board[r][0] == 'X' || board[r][0] == 'T') &&
					(board[r][1] == 'X' || board[r][1] == 'T') &&
					(board[r][2] == 'X' || board[r][2] == 'T') &&
					(board[r][3] == 'X' || board[r][3] == 'T');
			oW =	(board[r][0] == 'O' || board[r][0] == 'T') &&
					(board[r][1] == 'O' || board[r][1] == 'T') &&
					(board[r][2] == 'O' || board[r][2] == 'T') &&
					(board[r][3] == 'O' || board[r][3] == 'T');
		}
		for (int c = 0; !xW && !oW && c < 4; ++c)
		{
			xW =	(board[0][c] == 'X' || board[0][c] == 'T') &&
					(board[1][c] == 'X' || board[1][c] == 'T') &&
					(board[2][c] == 'X' || board[2][c] == 'T') &&
					(board[3][c] == 'X' || board[3][c] == 'T');
			oW =	(board[0][c] == 'O' || board[0][c] == 'T') &&
					(board[1][c] == 'O' || board[1][c] == 'T') &&
					(board[2][c] == 'O' || board[2][c] == 'T') &&
					(board[3][c] == 'O' || board[3][c] == 'T');
		}
		if (!xW && !oW)
		{
			xW =	(board[0][0] == 'X' || board[0][0] == 'T') &&
					(board[1][1] == 'X' || board[1][1] == 'T') &&
					(board[2][2] == 'X' || board[2][2] == 'T') &&
					(board[3][3] == 'X' || board[3][3] == 'T');
			oW =	(board[0][0] == 'O' || board[0][0] == 'T') &&
					(board[1][1] == 'O' || board[1][1] == 'T') &&
					(board[2][2] == 'O' || board[2][2] == 'T') &&
					(board[3][3] == 'O' || board[3][3] == 'T');
		}
		if (!xW && !oW)
		{
			xW =	(board[0][3] == 'X' || board[0][3] == 'T') &&
					(board[1][2] == 'X' || board[1][2] == 'T') &&
					(board[2][1] == 'X' || board[2][1] == 'T') &&
					(board[3][0] == 'X' || board[3][0] == 'T');
			oW =	(board[0][3] == 'O' || board[0][3] == 'T') &&
					(board[1][2] == 'O' || board[1][2] == 'T') &&
					(board[2][1] == 'O' || board[2][1] == 'T') &&
					(board[3][0] == 'O' || board[3][0] == 'T');
		}
		fprintf(output, "Case #%d: %s\n", i, oW ? "O won" : (xW ? "X won" : (hasEmpty ? "Game has not completed" : "Draw")));
	}

	fclose(output);
	fclose(input);

//	system("pause");
	return 0;
}