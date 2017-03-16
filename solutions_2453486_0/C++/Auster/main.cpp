#include <cstdio>

using namespace std;

int t;

char s[5][5];

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		for(int j = 0; j < 4; ++j)
			scanf("%s", s[j]);
		int O = 0;
		int X = 0;
		for(int j = 0; j < 4; ++j)
		{
			int tO = 0, tX = 0, tT = 0;
			for(int k = 0; k < 4; ++k)
			{
				tO += s[j][k] == 'O';
				tX += s[j][k] == 'X';
				tT += s[j][k] == 'T';
			}
			if (tO == 4 || tO == 3 && tT == 1)
				O = 1;
			if (tX == 4 || tX == 3 && tT == 1)
				X = 1;
		}
		for(int j = 0; j < 4; ++j)
		{
			int tO = 0, tX = 0, tT = 0;
			for(int k = 0; k < 4; ++k)
			{
				tO += s[k][j] == 'O';
				tX += s[k][j] == 'X';
				tT += s[k][j] == 'T';
			}
			if (tO == 4 || tO == 3 && tT == 1)
				O = 1;
			if (tX == 4 || tX == 3 && tT == 1)
				X = 1;
		}
		int tO = 0, tX = 0, tT = 0;
		for(int j = 0; j < 4; ++j)
		{
			tO += s[j][j] == 'O';
			tX += s[j][j] == 'X';
			tT += s[j][j] == 'T';
		}
		if (tO == 4 || tO == 3 && tT == 1)
			O = 1;
		if (tX == 4 || tX == 3 && tT == 1)
			X = 1;
		tO = 0, tX = 0, tT = 0;
		for(int j = 0; j < 4; ++j)
		{
			tO += s[3 - j][j] == 'O';
			tX += s[3 - j][j] == 'X';
			tT += s[3 - j][j] == 'T';
		}
		if (tO == 4 || tO == 3 && tT == 1)
			O = 1;
		if (tX == 4 || tX == 3 && tT == 1)
			X = 1;
		printf("Case #%d: ", i + 1);
		if (O && !X)
		{
			printf("O won\n");
			continue;
		}
		if (!O && X)
		{
			printf("X won\n");
			continue;
		}
		if (O && X)
			++*(char*)0;
		int empty = 0;
		for(int j = 0; j < 4; ++j)
			for(int k = 0; k < 4; ++k)
				empty += s[j][k] == '.';
		if (empty)
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	return 0;
}