#include <iostream>
using namespace std;

int main()
{
	int i, j, t, k;
	bool f;
	char x[4][4];
	char o[4][4];
	
	cin >> t;
	for (i = 1; i <= t; ++i)
	{
		f = true;
		for (j = 0; j < 4; ++j)
			for (k = 0; k < 4; ++k)
			{
				cin >> x[j][k];
				o[j][k] = x[j][k];
				if (x[j][k] == '.')
					f = false;
				if (x[j][k] == 'T')
				{
					x[j][k] = 'X';
					o[j][k] = 'O';
				}
			}
		k = 0;
		for (j = 0; j < 4; ++j)
		{
			if ((x[j][0] == 'X') && (x[j][1] == 'X') && (x[j][2] == 'X') && (x[j][3] == 'X'))
				k = 1;
			if ((o[j][0] == 'O') && (o[j][1] == 'O') && (o[j][2] == 'O') && (o[j][3] == 'O'))
				k = 2;
		}
		for (j = 0; j < 4; ++j)
		{
			if ((x[0][j] == 'X') && (x[1][j] == 'X') && (x[2][j] == 'X') && (x[3][j] == 'X'))
				k = 1;
			if ((o[0][j] == 'O') && (o[1][j] == 'O') && (o[2][j] == 'O') && (o[3][j] == 'O'))
				k = 2;
		}
		if ((x[0][0] == 'X') && (x[1][1] == 'X') && (x[2][2] == 'X') && (x[3][3] == 'X'))
			k = 1;
		if ((o[0][0] == 'O') && (o[1][1] == 'O') && (o[2][2] == 'O') && (o[3][3] == 'O'))
			k = 2;
		if ((x[3][0] == 'X') && (x[2][1] == 'X') && (x[1][2] == 'X') && (x[0][3] == 'X'))
			k = 1;
		if ((o[3][0] == 'O') && (o[2][1] == 'O') && (o[1][2] == 'O') && (o[0][3] == 'O'))
			k = 2;
		cout << "Case #" << i << ": ";
		if (k == 1)
			cout << "X won" << endl;
		else if (k == 2)
			cout << "O won" << endl;
		else if ((k == 0) && !f)
			cout << "Game has not completed" << endl;
		else
			cout << "Draw" << endl;
	}

	return 0;
}
