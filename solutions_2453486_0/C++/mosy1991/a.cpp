#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <ctime>
using namespace std;

typedef long long LL;

#define MAXN 100
int n = 4;
char s[MAXN][MAXN];

int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case #%d: ", ++cases);
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		bool xwon = false, owon = false;
		for (int i = 0; i < n; ++i)
		{
			bool flag = true;
			for (int j = 0; j < n; ++j)
				if (s[i][j] != 'X' && s[i][j] != 'T')
				{
					flag = false;
					break;
				}
			if (flag)
			{
				xwon = true;
				break;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			bool flag = true;
			for (int i = 0; i < n; ++i)
				if (s[i][j] != 'X' && s[i][j] != 'T')
				{
					flag = false;
					break;
				}
			if (flag)
			{
				xwon = true;
				break;
			}
		}	
		bool flag = true;
		for (int i = 0, j = n - 1; i < n; ++i, --j)
			if (s[i][j] != 'X' && s[i][j] != 'T')
			{
				flag = false;
				break;
			}
		if (flag) 
			xwon = true;
		flag = true;
		for (int i = 0; i < n; ++i)
			if (s[i][i] != 'X' && s[i][i] != 'T')
			{
				flag = false;
				break;
			}
		if (flag)
			xwon = true;
		if (xwon)
		{
			puts("X won");
			continue;
		}
		for (int i = 0; i < n; ++i)
		{
			bool flag = true;
			for (int j = 0; j < n; ++j)
				if (s[i][j] != 'O' && s[i][j] != 'T')
				{
					flag = false;
					break;
				}
			if (flag)
			{
				owon = true;
				break;
			}
		}

		for (int j = 0; j < n; ++j)
		{
			bool flag = true;
			for (int i = 0; i < n; ++i)
				if (s[i][j] != 'O' && s[i][j] != 'T')
				{
					flag = false;
					break;
				}
			if (flag)
			{
				owon = true;
				break;
			}
		}
		flag = true;
		for (int i = 0, j = n - 1; i < n; ++i, --j)
			if (s[i][j] != 'O' && s[i][j] != 'T')
			{
				flag = false;
				break;
			}
		if (flag)
			owon = true;
		flag = true;
		for (int i = 0; i < n; ++i)
			if (s[i][i] != 'O' && s[i][i] != 'T')
			{
				flag = false;
				break;
			}
		if (flag)
			owon = true;

		if (owon)
		{
			puts("O won");
			continue;
		}
		bool ending = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (s[i][j] == '.') ending = false;
		if (ending)
			puts("Draw");
		else puts("Game has not completed");
	}
	return 0;
}
