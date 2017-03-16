#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

int T;
char tick[4][5];

bool isWinner(char symbol)
{
	bool win = true;
	for(int i = 0; i < 4; i++)
	{
		win = true;
		for(int j = 0; j < 4; j++)
		{
			if(tick[i][j] != symbol && tick[i][j] != 'T') win = false;
		}
		if(win) return true;

		win = true;
		for(int j = 0; j < 4; j++)
		{
			if(tick[j][i] != symbol && tick[j][i] != 'T') win = false;
		}
		if(win) return true;
	}

	win = true;
	for(int i = 0; i < 4; i++)
	{
		if(tick[i][i] != symbol && tick[i][i] != 'T') win = false;
	}
	if(win) return true;

	win = true;
	for(int i = 0; i < 4; i++)
	{
		if(tick[i][3-i] != symbol && tick[i][3-i] != 'T') win = false;
	}
	
	return win;
}

bool isFinish()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(tick[i][j] == '.') return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &T);

	for(int c = 1; c <= T; c++)
	{
		for(int i = 0; i < 4; i++)
		{
			scanf("%s", tick[i]);
		}

		printf("Case #%d: ", c);
		if(isWinner('X')) puts("X won");
		else if(isWinner('O')) puts("O won");
		else if(isFinish()) puts("Draw");
		else puts("Game has not completed");

	}


	return 0;
}
