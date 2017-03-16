#include <cstdio>

bool flag;
char a[10][10], ch[10];
int test;

bool check()
{
	int cntO = 0;
	int cntX = 0;
	for (int i = 1; i <= 4; ++i)
	{
		if (ch[i] == '.')
			return flag = 0;
		if (ch[i] == 'O')
			++cntO;
		else if (ch[i] == 'X')
			++cntX;
	}
	if (cntO == 4 || cntO == 3 && cntX == 0)
	{
		puts("O won");
		return 1;
	}
	if (cntX == 4 || cntX == 3 && cntO == 0)
	{
		puts("X won");
		return 1;
	}
	return 0;
}

void solve(int kase)
{
	printf("Case #%d: ", kase);
	flag = 1;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
			ch[j] = a[i][j];
		if (check())
			return;
	}
	for (int j = 1; j <= 4; ++j)
	{
		for (int i = 1; i <= 4; ++i)
			ch[i] = a[i][j];
		if (check())
			return;
	}
	for (int i = 1; i <= 4; ++i)
		ch[i] = a[i][i];
	if (check())
		return;
	for (int i = 1; i <= 4; ++i)
		ch[i] = a[i][5 - i];
	if (check())
		return;
	puts(flag ? "Draw" : "Game has not completed");
}

int main()
{
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		for (int i = 1; i <= 4; ++i)
		{
			scanf("%s", ch + 1);
			for (int j = 1; j <= 4; ++j)
				a[i][j] = ch[j];
		}
		solve(kase);
	}
	
	return 0;
}
