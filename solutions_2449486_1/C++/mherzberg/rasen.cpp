#include <iostream>

using namespace std;

bool checkTile(int** board, int width, int height, int x, int y)
{
	int value = board[y][x];
	
	bool found = false;
	
	// check vertical
	for (int a = 0; a < height; a++)
	{
		if (board[a][x] > value)
		{
			found = true;
			break;
		}
	}
	
	if (!found)
	{
		return true;
	}
	
	// check horizontal
	for (int b = 0; b < width; b++)
	{
		if (board[y][b] > value && found)
		{
			return false;
		}
	}
	
	return true;
}

bool isCuttable(int** board, int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (!checkTile(board, width, height, x, y))
			{
				return false;
			}
		}
	}
	
	return true;
}

int main()
{
	int cases;
	cin >> cases;
	
	for (int i = 0; i < cases; i++)
	{
		int height, width;
		cin >> height >> width;
		int** board = new int*[height];
		
		for (int y = 0; y < height; y++)
		{
			board[y] = new int[width];
			for (int x = 0; x < width; x++)
			{
				int h;
				cin >> h;
				board[y][x] = h;
			}
		}
		
		cout << "Case #" << i + 1 << ": ";
		
		if (isCuttable(board, width, height))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		
		for (int y = 0; y < height; y++)
		{
			delete board[y];
		}		
		delete board;
	}
	
	return 0;
}
