
#include <iostream>

using namespace std;

int block[4][4];

void analyse(int sum, bool &x, bool &y)
{
	if (sum == 1) x = true;
	else if (sum == 2) y = true;
}

int sumrow(int r)
{
	return block[r][0] & block[r][1] & block[r][2] & block[r][3];
}

int sumcol(int c)
{
	return block[0][c] & block[1][c] & block[2][c] & block[3][c];
}


int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		bool x = false, y = false, e = false;

		for (int r = 0; r < 4; r++)
		{
			string s;
			cin >> s;
			for (int c = 0; c < 4; c++)
			{
				block[r][c] = (s[c] == 'X' ? 1 : (s[c] == 'O' ? 2 : (s[c] == 'T' ? 3 : 0)));
				if (block[r][c] == 0) e = true;
			}
		}

		// rows, cols, diags
		for (int r = 0; r < 4; r++) analyse(sumrow(r), x, y);
		for (int c = 0; c < 4; c++) analyse(sumcol(c), x, y);
		analyse(block[0][0] & block[1][1] & block[2][2] & block[3][3], x, y);
		analyse(block[0][3] & block[1][2] & block[2][1] & block[3][0], x, y);

		cout << "Case #" << (i+1) << ": ";
		if (x)
		{
			cout << "X won";
		} else if (y)
		{
			cout << "O won";
		} else if (e)
		{
			cout << "Game has not completed";
		} else
		{
			cout << "Draw";
		}
		cout << endl;
	}

	return 0;
}

