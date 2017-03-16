#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char mp[8][8];

bool full()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (mp[i][j] == '.')
				return false;
}

bool check(char c)
{
	for (int i = 0; i < 4; ++i)
	{
		int v = 0;
		for (int j = 0; j < 4; ++j)
			if (mp[i][j] == c || mp[i][j] == 'T')
				++v;
		if (v == 4) return true;
	}

	for (int j = 0; j < 4; ++j)
	{
		int v = 0;
		for (int i = 0; i < 4; ++i)
			if (mp[i][j] == c || mp[i][j] == 'T')
				++v;
		if (v == 4) return true;
	}

	{
		int v = 0;
		for (int i = 0; i < 4; ++i)
			if (mp[i][i] == c || mp[i][i] == 'T')
				++v;
		if (v == 4) return true;
	}

	{
		int v = 0;
		for (int i = 0; i < 4; ++i)
			if (mp[i][3 - i] == c || mp[i][3 - i] == 'T')
				++v;
		if (v == 4) return true;
	}

	return false;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ct = 1; ct <= T; ++ct)
	{
		for (int i = 0; i < 4; ++i)
			scanf("%s", mp[i]);

		printf("Case #%d: ", ct);

		if (check('X'))
		{
			printf("X won\n");
		}
		else if (check('O'))
		{
			printf("O won\n");
		}
		else if (full())
		{
			printf("Draw\n");
		}
		else
		{
			printf("Game has not completed\n");
		}
	}
}