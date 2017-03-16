
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

char field[4][4];

bool IsWin(char pl)
{
	for(int col = 0; col < 4; col++)
	{
		if( (field[0][col] == pl || field[0][col] == 'T') &&
			(field[1][col] == pl || field[1][col] == 'T') &&
			(field[2][col] == pl || field[2][col] == 'T') &&
			(field[3][col] == pl || field[3][col] == 'T') 
			)
		{return true;}
	}
	
	for(int row = 0; row < 4; row++)
	{
		if( (field[row][0] == pl || field[row][0] == 'T') &&
			(field[row][1] == pl || field[row][1] == 'T') &&
			(field[row][2] == pl || field[row][2] == 'T') &&
			(field[row][3] == pl || field[row][3] == 'T') 
			)
		{return true;}
	}

	if( (field[0][0] == pl || field[0][0] == 'T') &&
		(field[1][1] == pl || field[1][1] == 'T') &&
		(field[2][2] == pl || field[2][2] == 'T') &&
		(field[3][3] == pl || field[3][3] == 'T') 
		)
	{return true;}

	if( (field[0][3] == pl || field[0][3] == 'T') &&
		(field[1][2] == pl || field[1][2] == 'T') &&
		(field[2][1] == pl || field[2][1] == 'T') &&
		(field[3][0] == pl || field[3][0] == 'T') 
	)
	{return true;}


	return false;
}

int main()
{
	freopen("output.out", "w", stdout);
	freopen("input.in", "r", stdin);

	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		char c;
		bool iSDot = false;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				cin >> c;
				if(c == '.')
					iSDot = true;
				field[i][j] = c;
			}
		}

		bool Owin = IsWin('O');
		bool Xwin = IsWin('X');
	
		if(Owin && Xwin)
		{
			printf("Case #%d: %s", tt+1, "Draw");
		}
		else if(Owin)
		{
			printf("Case #%d: %s", tt+1, "O won");
		}
		else if(Xwin)
		{
			printf("Case #%d: %s", tt+1, "X won");
		}
		else if(iSDot)
		{
			printf("Case #%d: %s", tt+1, "Game has not completed");
		}
		else
		{
			printf("Case #%d: %s", tt+1, "Draw");
		}

		if(tt != t-1)
			printf("\n");
	}
	return 0;
}