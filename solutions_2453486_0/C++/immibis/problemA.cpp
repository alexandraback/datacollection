#include <stdio.h>

#define FILENAME "Asmall.txt"

char board[4][4];
char result;

bool checkMatch(char a, char player)
{
	return a == player || a == 'T';
}

void checkMatch(char a, char b, char c, char d, char player)
{
	if(checkMatch(a, player) && checkMatch(b, player) && checkMatch(c, player) && checkMatch(d, player))
	{
		if(result != '\0' && result != player)
			result = '!';
		else
			result = player;
	}
}

void checkRow(int row, char player)
{
	checkMatch(board[row][0], board[row][1], board[row][2], board[row][3], player);
}

void checkCol(int col, char player)
{
	checkMatch(board[0][col], board[1][col], board[2][col], board[3][col], player);
}

void checkDiagonal1(char player)
{
	checkMatch(board[0][0], board[1][1], board[2][2], board[3][3], player);
}

void checkDiagonal2(char player)
{
	checkMatch(board[3][0], board[2][1], board[1][2], board[0][3], player);
}

void checkTie()
{
	if(result != '\0')
		return;

	result = 'T';

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(board[i][j] == '.')
			{
				result = '\0';
				return;
			}
}

int main(int argc, char **argv)
{
	freopen(FILENAME, "r", stdin);
	freopen("output.txt", "w", stdout);

	int numCases;
	scanf("%i ", &numCases);

	for(int c = 1; c <= numCases; c++)
	{
		for(int row = 0; row < 4; row++)
		{
			for(int col = 0; col < 4; col++)
			{
				char ch;
				scanf("%c ", &ch);
				board[row][col] = ch;
				if(ch != 'X' && ch != 'O' && ch != '.' && ch != 'T')
				{
					fprintf(stderr, "Invalid character '%c' at case %i row %i col %i (1-based)\n", ch, c, row+1, col+1);
					return 1;
				}
			}
		}

		result = '\0';

		for(int row = 0; row < 4; row++)
		{
			checkRow(row, 'O');
			checkRow(row, 'X');
			checkCol(row, 'O');
			checkCol(row, 'X');
		}

		checkDiagonal1('O');
		checkDiagonal1('X');
		checkDiagonal2('O');
		checkDiagonal2('X');

		if(result == '\0')
			checkTie();

		switch(result)
		{
		case 'O': printf("Case #%i: O won\n", c); break;
		case 'X': printf("Case #%i: X won\n", c); break;
		case 'T': printf("Case #%i: Draw\n", c); break;
		case '\0': printf("Case #%i: Game has not completed\n", c); break;
		default:
			printf("Case #%i: Invalid result code '%c' (%i)\n", c, result, result);
			return 1;
		}
	}

	return 0;
}