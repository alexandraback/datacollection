#include <cstdio>
#include <cstring>

const int n = 4;

char s[n + 1][n + 1];
int ans, cnt;

int check_row(int x, int y)
{
	int c[n];
	c[0] = c[1] = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[x][y + i] == 'X')
			++c[0];
		if (s[x][y + i] == 'O')
			++c[1];
		if (s[x][y + i] == 'T')
		{
			++c[0]; ++c[1];
		}
	}
	if (c[0] == n)
		return 2;
	if (c[1] == n)
		return 3;
	return ans;
}

int check_column(int x, int y)
{
	int c[n];
	c[0] = c[1] = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[x + i][y] == 'X')
			++c[0];
		if (s[x + i][y] == 'O')
			++c[1];
		if (s[x + i][y] == 'T')
		{
			++c[0]; ++c[1];
		}
	}
	if (c[0] == n)
		return 2;
	if (c[1] == n)
		return 3;
	return ans;
}

int check_diag()
{
	int c[n];
	int x = 0, y = 0;
	c[0] = c[1] = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[x + i][y + i] == 'X')
			++c[0];
		if (s[x + i][y + i] == 'O')
			++c[1];
		if (s[x + i][y + i] == 'T')
		{
			++c[0]; ++c[1];
		}
	}
	if (c[0] == n)
		return 2;
	if (c[1] == n)
		return 3;
	c[0] = c[1] = 0;
	x = 0; y = 3;
	for (int i = 0; i < n; ++i)
	{
		if (s[x + i][y - i] == 'X')
			++c[0];
		if (s[x + i][y - i] == 'O')
			++c[1];
		if (s[x + i][y - i] == 'T')
		{
			++c[0]; ++c[1];
		}
	}
	if (c[0] == n)
		return 2;
	if (c[1] == n)
		return 3;
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		ans = 0, cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
			for (int j = 0; j < n; ++j)
				if (s[i][j] != '.')
					++cnt;
		}
		if (cnt == n * n)
			ans = 1;
		for (int i = 0; i < n; ++i)
		{
			ans = check_row(i, 0);
			if (ans > 1)
				break;
			ans = check_column(0, i);
			if (ans > 1)
				break;
		}
		if (ans <= 1)
			ans = check_diag();
		printf("Case #%d: ", tt);
		if (ans == 0)
		{
			puts("Game has not completed");
		}
		if (ans == 1)
		{
			puts("Draw");
		}
		if (ans == 2)
		{
			puts("X won");
		}
		if (ans == 3)
		{
			puts("O won");
		}
	}

	return 0;
}
