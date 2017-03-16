#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
char map[10][10];

bool win(char ch)
{
	for (int i = 1; i <= 4; ++i)
	{
		bool flag = true;
		for (int j = 0; j < 4 && flag; ++j)
			if (map[i][j] != ch && map[i][j] != 'T') flag = false;
		if (flag) return true;
	}
	for (int i = 0; i < 4; ++i)
	{
		bool flag = true;
		for (int j = 1; j <= 4 && flag; ++j)
			if (map[j][i] != ch && map[j][i] != 'T') flag = false;
		if (flag) return true;
	}
	bool flag = true;
	for (int i = 1; i <= 4 && flag; ++i)
		if (map[i][i - 1] != ch && map[i][i - 1] != 'T') flag = false;
	if (flag) return true;
	flag = true;
	for (int i = 1; i <= 4 && flag; ++i)
		if (map[i][4 - i] != ch && map[i][4 - i] != 'T') flag = false;
	if (flag) return true;
	return false;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		bool flag = false;
		for (int j = 1; j <= 4; ++j)
		{
			scanf("%s",map[j]);
			for (int k = 0; k < 4; ++k) if (map[j][k] == '.') flag = true;
		}
		
		if (win('O')) printf("Case #%d: O won\n", i); else
		if (win('X')) printf("Case #%d: X won\n", i); else
		if (flag) printf("Case #%d: Game has not completed\n", i); else
			printf("Case #%d: Draw\n", i);
	}
	return 0;
}
