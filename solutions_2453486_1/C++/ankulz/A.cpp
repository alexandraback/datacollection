#include <iostream>
#include <string>
using namespace std;

main()
{
	int T;
	cin >> T;

	for (int index = 1; index <= T; index++)
	{
		cout << "Case #" << index << ": ";
		string board[4];
		for (int i = 0; i < 4; i++)
		{
			cin >> board[i];
		}

		bool fCrossWin = false;
		bool fZeroWin = false;
		string crossWinString[] = {"XXXX", "TXXX", "XTXX", "XXTX", "XXXT"};
		string zeroWinString[] = {"OOOO", "TOOO", "OTOO", "OOTO", "OOOT"};

		// row wise
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (board[i] == crossWinString[j])
				{
					fCrossWin = true;
				}
				else if (board[i] == zeroWinString[j])
				{
					fZeroWin = true;
				}
			}
		}

		// column wise
		for (int i = 0; i < 4; i++)
		{
			string col;
			for (int j = 0; j < 4; j++)
			{
				col += board[j][i];
			}
			for (int j = 0; j < 5; j++)
			{
				if (col == crossWinString[j])
				{
					fCrossWin = true;
				}
				else if (col == zeroWinString[j])
				{
					fZeroWin = true;
				}
			}
		}

		// diagonal wise
		string diag;
		diag += board[0][0];
		diag += board[1][1];
		diag += board[2][2];
		diag += board[3][3];
		for (int i = 0; i < 5; i++)
		{
			if (diag == crossWinString[i])
			{
				fCrossWin = true;
			}
			else if (diag == zeroWinString[i])
			{
				fZeroWin = true;
			}
		}

		diag = "";
		diag += board[3][0];
		diag += board[2][1];
		diag += board[1][2];
		diag += board[0][3];
		for (int i = 0; i < 5; i++)
		{
			if (diag == crossWinString[i])
			{
				fCrossWin = true;
			}
			else if (diag == zeroWinString[i])
			{
				fZeroWin = true;
			}
		}

		if (fCrossWin && fZeroWin)
		{
			cout << "Draw\n";
		}
		else if (fCrossWin)
		{
			cout << "X won\n";
		}
		else if (fZeroWin)
		{
			cout << "O won\n";
		}
		else if (!fCrossWin && !fZeroWin)
		{
			bool fGameComplete = true;
			for (int i = 0; i < 4; i++)
			{
				if (board[i].find('.') != -1)
				{
					fGameComplete = false;
					break;
				}
			}
			if (fGameComplete)
			{
				cout << "Draw\n";
			}
			else
			{
				cout << "Game has not completed\n";
			}
		}
	}
}