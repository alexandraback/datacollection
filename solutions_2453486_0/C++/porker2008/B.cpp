#include <iostream>
using namespace std;

char map[4][4];

int main()
{
	int n;
	cin >> n;
	for(int c=1;c<=n;c++)
	{
		int winner = 0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				cin >> map[i][j];
		}
		cout << "Case #" << c << ": ";
		bool finish = true;
		for(int i=0;i<4;i++)
		{
			bool win = true, win2 = true, win3 = true, win4 = true;
			for(int j=0;j<4;j++)
			{
				if(map[i][j] != 'X' && map[i][j] != 'T')
					win = false;
				if(map[i][j] != 'O' && map[i][j] != 'T')
					win3 = false;
				if(map[j][i] != 'X' && map[j][i] != 'T')
					win2 = false;
				if(map[j][i] != 'O' && map[j][i] != 'T')
					win4 = false;
				if(map[i][j] == '.')
					finish = false;
			}
			if(win || win2)
				winner = 1;
			else if(win3 || win4)
				winner = 2;
		}
		bool win = true, win2 = true, win3 = true, win4 = true;
		for(int i=0;i<4;i++)
		{
			if(map[i][i] != 'X' && map[i][i] != 'T')
				win = false;
			if(map[i][i] != 'O' && map[i][i] != 'T')
				win3 = false;
			if(map[i][3-i] != 'X' && map[i][3-i] != 'T')
				win2 = false;
			if(map[i][3-i] != 'O' && map[i][3-i] != 'T')
				win4 = false;
		}
		if(win || win2)
			winner = 1;
		else if(win3 || win4)
			winner = 2;
		if(winner)
		{
			if(winner == 1)
				cout << "X won" << endl;
			else
				cout << "O won" << endl;
		}
		else
		{
			if(finish)
				cout << "Draw" << endl;
			else
				cout << "Game has not completed" << endl;
		}
	}
	system("pause");
}