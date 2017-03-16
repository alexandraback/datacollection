#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char field[4][4];

bool check(char c)
{
	bool diag1 = true;
	bool diag2 = true;

	for (int i = 0; i < 4; ++i)
	{
		if (field[i][i] != c && field[i][i] != 'T')
			diag1 = false;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (field[3 - i][i] != c && field[3 - i][i] != 'T')
			diag2 = false;
	}

	bool row = false;
	bool col = false;

	for (int i = 0; i < 4 && !row; ++i)
	{
		bool cur_row = true;
		for (int j = 0; j < 4; ++j)
		{
			if (field[i][j] != c && field[i][j] != 'T')
				cur_row = false;
		}

		if (cur_row)
			row = cur_row;
	}

	for (int i = 0; i < 4 && !col; ++i)
	{
		bool cur_col = true;
		for (int j = 0; j < 4; ++j)
		{
			if (field[j][i] != c && field[j][i] != 'T')
				cur_col = false;
		}

		if (cur_col)
			col = cur_col;
	}

	return diag1 || diag2 || row || col;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-result.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		memset(field, 0, sizeof(field));

		bool has_empty = false;
		for (int j = 0; j < 4; ++j)
		{
			string s;
			cin >> s;
			for (int k = 0; k <4; ++k)
			{
				field[j][k] = s[k];
				if (s[k] == '.')
					has_empty = true;
			}
		}

		printf("Case #%d: ", i + 1);
		if (check('X'))
			printf("X won");
		else if (check('O'))
			printf("O won");
		else if (has_empty)
			printf("Game has not completed");
		else
			printf("Draw");

		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}