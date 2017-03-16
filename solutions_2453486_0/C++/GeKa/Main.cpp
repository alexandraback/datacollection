#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>


using namespace std;

char matr[4][4];

bool wan(char c)
{
	bool f = true;
	for (int i = 0; i < 4; i++)
		if (matr[i][i] != c && matr[i][i] != 'T')
			f = false;
	if (f)
		return true;

	f = true;
	for (int i = 0; i < 4; i++)
		if (matr[i][3 - i] != c && matr[i][3-i] != 'T')
			f = false;
	if (f)
		return true;

	for (int i = 0; i < 4; i++)
	{
		f = true;
		for (int j = 0; j < 4; j++)
			if (matr[i][j] !=c && matr[i][j] != 'T')
				f = false;
		if (f)
			return true;
	}

	for (int i = 0; i < 4; i++)
	{
		f = true;
		for (int j = 0; j < 4; j++)
			if (matr[j][i] !=c && matr[j][i] != 'T')
				f = false;
		if (f)
			return true;
	}
	return false;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		char s[10];
		bool isEmpty = false;
		for (int i = 0; i <4; i++)
		{
			scanf("%s", s);
			for (int j = 0; j < 4; j++)
			{
				matr[i][j] = s[j];
				if  (matr[i][j] == '.')
					isEmpty = true;
			}
		}
		printf("Case #%d: ", t+1);
		if (wan('X'))
			printf("X won");
		else if (wan('O'))
			printf("O won");
		else if (isEmpty)
			printf("Game has not completed");
		else
			printf("Draw");
		printf("\n");
	}

	return 0;
}