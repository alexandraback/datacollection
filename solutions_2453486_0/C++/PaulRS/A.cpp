#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int c = 1; c <= n; c++)
	{
		cout << "Case #" << c << ": ";
		vector <string> a(4,string());
		for (int i = 0; i < 4; i++)
			cin >> a[i];
		int fr = 0;
		int x = 0, o = 0, t = 0;
		int X = 0, O = 0, T = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (a[i][j] == '.')	fr++;
		for (int i = 0; i < 4; i++)
		{
			x = 0, o = 0, t = 0;
			X = 0, O = 0, T = 0;
			for (int j = 0; j < 4; j++)
			{
				if ( a[i][j] == 'X')	x++;
				else if (a[i][j] == 'O')	o++;
				else if (a[i][j] != '.')	t++;
				if ( a[j][i] == 'X')	X++;
				else if (a[j][i] == 'O')	O++;
				else if (a[j][i] != '.')	T++;
			}
			if ( x + t == 4 || X + T == 4)
			{
				cout << "X won\n";
				goto nxt;
			} else if ( o + t == 4 || O + T == 4)
			{
				cout << "O won\n";
				goto nxt;
			}
		}
		x = 0, o = 0, t = 0;
		X = 0, O = 0, T = 0;
		for (int i = 0; i < 4; i++)
		{
			if ( a[i][i] == 'X')	x++;
			else if (a[i][i] == 'O')	o++;
			else if (a[i][i] != '.')	t++;
			if ( a[i][3-i] == 'X')	X++;
			else if (a[i][3-i] == 'O')	O++;
			else if (a[i][3-i] != '.')	T++;
		}
		if ( x + t == 4 || X + T == 4)
		{
			cout << "X won\n";
			goto nxt;
		} else if ( o + t == 4 || O + T == 4)
		{
			cout << "O won\n";
			goto nxt;
		}
		if (fr > 0)
			cout << "Game has not completed\n";
		else
			cout << "Draw\n";
		nxt:;
	}
	return 0;
}
