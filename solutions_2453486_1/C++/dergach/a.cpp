#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;

char a[2][10][10];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		gets(a[0][7]);
		for(int i = 0; i < 4; i++)
			gets(a[0][i]);
		int x = -1, y = -1;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				if(a[0][i][j] == 'T')
					x = i, y = j;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				a[1][i][j] = a[0][i][j];
		if(x != -1 && y != -1)
		{
			a[0][x][y] = 'X';
			a[1][x][y] = 'O';
		}
		bool X = false, O = false;
		for(int k = 0; k < 2; k++)
		{
			for(int i = 0; i < 4; i++)
			{
				if(a[k][i][0] == 'X' && a[k][i][1] == 'X' && a[k][i][2] == 'X' && a[k][i][3] == 'X')
					X = true;
				if(a[k][i][0] == 'O' && a[k][i][1] == 'O' && a[k][i][2] == 'O' && a[k][i][3] == 'O')
					O = true;
				if(a[k][0][i] == 'X' && a[k][1][i] == 'X' && a[k][2][i] == 'X' && a[k][3][i] == 'X')
					X = true;
				if(a[k][0][i] == 'O' && a[k][1][i] == 'O' && a[k][2][i] == 'O' && a[k][3][i] == 'O')
					O = true;
			}
			if(a[k][0][0] == 'X' && a[k][1][1] == 'X' && a[k][2][2] == 'X' && a[k][3][3] == 'X')
				X = true;
			if(a[k][0][0] == 'O' && a[k][1][1] == 'O' && a[k][2][2] == 'O' && a[k][3][3] == 'O')
				O = true;
			if(a[k][0][3] == 'X' && a[k][1][2] == 'X' && a[k][2][1] == 'X' && a[k][3][0] == 'X')
				X = true;
			if(a[k][0][3] == 'O' && a[k][1][2] == 'O' && a[k][2][1] == 'O' && a[k][3][0] == 'O')
				O = true;
		}
		if(X)
			printf("Case #%d: X won\n", t);
		else
			if(O)
				printf("Case #%d: O won\n", t);
			else
			{
				bool draw = true;
				for(int i = 0; i < 4; i++)
					for(int j = 0; j < 4; j++)
						if(a[0][i][j] == '.')
							draw = false;
				if(draw)
					printf("Case #%d: Draw\n", t);
				else
					printf("Case #%d: Game has not completed\n", t);
			}
	}
	return 0;
}