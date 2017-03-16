#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;
#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}


char s[10][10];

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	for(int i = 0; i < 4; i++)
		scanf("%s", s[i]);

	int x3 = 0, x4 = 0, o3 = 0, o4 = 0;
	for(int i = 0; i < 4; i++)
	{
		int x1 = 0, o1 = 0, x2 = 0, o2 = 0;
		for(int j = 0; j < 4; j++)
		{
			if (s[i][j] == 'X' || s[i][j] == 'T')
				x1++;
			if (s[i][j] == 'O' || s[i][j] == 'T')
				o1++;
			if (s[j][i] == 'X' || s[j][i] == 'T')
				x2++;
			if (s[j][i] == 'O' || s[j][i] == 'T')
				o2++;
		}
		if (x1 == 4 || x2 == 4)
		{
			printf("X won\n");
			return;
		}
		if (o1 == 4 || o2 == 4)
		{
			printf("O won\n");
			return;
		}
		if (s[i][i] == 'X' || s[i][i] == 'T')
			x3++;
		if (s[i][3-i] == 'X' || s[i][3-i] == 'T')
			x4++;
		if (s[i][i] == 'O' || s[i][i] == 'T')
			o3++;
		if (s[i][3-i] == 'O' || s[i][3-i] == 'T')
			o4++;
	}
	if (x3 == 4 || x4 == 4)
	{
		printf("X won\n");
		return;
	}
	if (o3 == 4 || o4 == 4)
	{
		printf("O won\n");
		return;
	}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			if (s[i][j] == '.')
			{
				printf("Game has not completed\n");
				return;
			}
		}
	printf("Draw\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
