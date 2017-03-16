#include <iostream>
#include <string>

using namespace std;

bool hasWon(char board[4][4], char player)
{
	// horizontally
	for (int y = 0; y < 4; y++)
	{
		if ((board[y][0] == player || board[y][0] == 'T') && 
			(board[y][1] == player || board[y][1] == 'T') && 
			(board[y][2] == player || board[y][2] == 'T') && 
			(board[y][3] == player || board[y][3] == 'T'))
		{
			return true;
		}
	}
	
	// vertically
	for (int x = 0; x < 4; x++)
	{
		if ((board[0][x] == player || board[0][x] == 'T') && 
			(board[1][x] == player || board[1][x] == 'T') && 
			(board[2][x] == player || board[2][x] == 'T') && 
			(board[3][x] == player || board[3][x] == 'T'))
		{
			return true;
		}
	}
	
	// diagonal
	if ((board[0][0] == player || board[0][0] == 'T') && 
		(board[1][1] == player || board[1][1] == 'T') && 
		(board[2][2] == player || board[2][2] == 'T') && 
		(board[3][3] == player || board[3][3] == 'T'))
	{
		return true;
	}
	
	if ((board[0][3] == player || board[0][3] == 'T') && 
		(board[1][2] == player || board[1][2] == 'T') && 
		(board[2][1] == player || board[2][1] == 'T') && 
		(board[3][0] == player || board[3][0] == 'T'))
	{
		return true;
	}
	
	return false;
}

bool stonesLeft(char board[4][4])
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (board[y][x] == '.')
			{
				return true;
			}
		}
	}
	
	return false;
}

int main()
{
	int cases;
	cin >> cases;
	
	for (int i = 0; i < cases; i++)
	{
		char board[4][4];
		
		for (int y = 0; y < 4; y++)
		{
			string line;
			cin >> line;
			
			for (int x = 0; x < 4; x++)
			{
				board[y][x] = line[x];
			}
		}
		
		cout << "Case #" << i + 1 << ": ";
		
		bool xwon = hasWon(board, 'X');
		bool owon = hasWon(board, 'O');
		
		if (xwon && owon)
		{
			cout << "Draw" << endl;
		}
		else if (xwon)
		{
			cout << "X won" << endl;
		}
		else if (owon)
		{
			cout << "O won" << endl;
		}
		else
		{
			if (stonesLeft(board))
			{
				cout << "Game has not completed" << endl;
			}
			else
			{
				cout << "Draw" << endl;
			}
		}		
		
	}
	
	return 0;
}
