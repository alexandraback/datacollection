#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool match(char b, char e)
{
	return b == e || b == 'T';
}

int main()
{
	int t;
	cin >> t;
	for (int caseNum = 1; caseNum <= t; caseNum++)
	{
		string board[4];
		for (int r = 0; r < 4; r++)
			cin >> board[r];

		int result = -1;
		for (int player = 0; player < 2; player++)
		{
			char ch = (player == 0) ? 'X' : 'O';
			bool d1 = true, d2 = true;
			bool gotRowCol = false;
			for (int i = 0; i < 4; i++)
			{
				d1 = d1 & match(board[i][i], ch);
				d2 = d2 & match(board[i][3 - i], ch);
				bool row = true;
				bool col = true;
				for (int j = 0; j < 4; j++)
				{
					row = row & match(board[i][j], ch);
					col = col & match(board[j][i], ch);
				}

				if (row || col)
				{
					gotRowCol = true;
					break;
				}
			}

			if (gotRowCol || d1 || d2)
			{
				result = player;
				break;
			}
		}

		if (result == -1)
		{
			bool hasEmpty = false;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					hasEmpty = hasEmpty || board[i][j] == '.';
			if (hasEmpty)
				result = 3;
			else
				result = 2;
		}

		cout << "Case #" << caseNum << ": ";
		switch (result) {
		case 0: cout << "X won" << endl; break;
		case 1: cout << "O won" << endl; break;
		case 2: cout << "Draw" << endl; break;
		case 3: cout << "Game has not completed" << endl; break;
		default: assert(false); break;
		}
	}

	return 0;
}
