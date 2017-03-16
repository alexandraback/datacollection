#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

char graph[4][4];

bool isWin(char A)
{
	bool bWin = true;
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		bWin = true;
		count = 0;
		for (int j = 0; j < 4; j++)
		{
			if (graph[i][j] == A)
			{
				count++;
			}
			else if (graph[i][j] == 'T')
			{
			}
			else
			{
				bWin = false;
				break;
			}
		}

		if (bWin && count >= 3)
			return true;
	}

	for (int i = 0; i < 4; i++)
	{
		bWin = true;
		count = 0;
		for (int j = 0; j < 4; j++)
		{
			if (graph[j][i] == A)
			{
				count++;
			}
			else if (graph[j][i] == 'T')
			{
			}
			else
			{
				bWin = false;
				break;
			}
		}

		if (bWin && count >= 3)
			return true;
	}

	bWin = true;
	count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (graph[i][i] == A)
		{
			count++;
		}
		else if (graph[i][i] == 'T')
		{
		}
		else
		{
			bWin = false;
			break;
		}
	}
	if (bWin && count >= 3)
		return true;

	bWin = true;
	count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (graph[3 - i][i] == A)
		{
			count++;
		}
		else if (graph[3 - i][i] == 'T')
		{
		}
		else
		{
			bWin = false;
			break;
		}
	}
	if (bWin && count >= 3)
		return true;
	return false;
}
void _main()
{
	char str[5];
	for (int i = 0; i < 4; i++)
	{
		scanf("%s", str);
		if (strlen(str) == 0)
			scanf("%s", str);
		for (int j = 0; j < 4; j++)
		{
			graph[i][j] = str[j];
			if (graph[i][j] != '.' && graph[i][j] != 'X' && graph[i][j] != 'T' && graph[i][j] != 'O')
				assert(false);
		}
	}

	if (isWin('X'))
		puts("X won");
	else if (isWin('O'))
		puts("O won");
	else
	{
		int cur = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cur += (int)(graph[i][j] != '.');
			}
		}

		if (cur < 16)
		{
			puts("Game has not completed");
		}
		else
		{
			puts("Draw");
		}
	}
}
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++)
	{
		printf("Case #%d: ", i);
		_main();
	}

}