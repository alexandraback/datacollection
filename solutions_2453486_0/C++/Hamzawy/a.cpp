/*
 * a.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

char b[5][5];

bool win(char c)
{
	for (int i = 0; i < 4; ++i)
	{
		bool f = 1;
		for (int j = 0; j < 4; ++j)
			if (b[i][j] != c && b[i][j] != 'T')
			{
				f = 0;
				break;
			}
		if (f)
			return 1;
		f = 1;
		for (int j = 0; j < 4; ++j)
			if (b[j][i] != c && b[j][i] != 'T')
			{
				f = 0;
				break;
			}
		if (f)
			return 1;
	}
	bool f = 1;
	for (int i = 0; i < 4; ++i)
		if (b[i][i] != c && b[i][i] != 'T')
		{
			f = 0;
			break;
		}
	if (f)
		return 1;
	f = 1;
	for (int i = 0; i < 4; ++i)
		if (b[i][3 - i] != c && b[i][3 - i] != 'T')
		{
			f = 0;
			break;
		}
	return f;
}

bool draw()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (b[i][j] == '.')
				return 0;
	return 1;
}

int main()
{
//	freopen("a.in", "rt", stdin);
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("a.out1", "wt", stdout);
	int tc;
	scanf("%d", &tc);
	for (int T = 1; T <= tc; ++T)
	{
		for (int i = 0; i < 4; ++i)
			scanf("%s", b[i]);
		if (win('X'))
			printf("Case #%d: X won\n", T);
		else if (win('O'))
			printf("Case #%d: O won\n", T);
		else if (draw())
			printf("Case #%d: Draw\n", T);
		else
			printf("Case #%d: Game has not completed\n", T);
	}
	return 0;
}
