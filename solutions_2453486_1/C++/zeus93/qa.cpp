#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std;
char s[5][5];
bool judge(char c)
{
	int i,j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
			if(s[i][j] != c)
				break;
		if(j == 4)
		{
			return true;
		}
	}
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
			if(s[j][i] != c)
				break;
		if(j == 4)
		{
			return true;
		}
	}
	for(i = 0; i < 4; i++)
		if(s[i][i] != c)
			break;
	if(i == 4)
		return true;
	for(i = 0; i < 4; i++)
		if(s[i][3 - i] != c)
			break;
	if(i == 4)
		return true;
	return false;
}
int main()
{
	int tcase, icase = 1;
	int i,j;
	scanf("%d", &tcase);
	while(tcase--)
	{
		int tx = -1, ty = -1;
		for(i = 0; i < 4; i++)
			scanf("%s", s[i]);
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
			{
				if(s[i][j] == 'T')
				{
					tx = i;
					ty = j;
				}
			}
		}
		if(tx != -1)
		{
			s[tx][ty] = 'X';
		}
		bool flag  = judge('X');
		printf("Case #%d: ", icase++);
		if(flag)
		{
			printf("X won\n");
			continue;
		}
		if(tx != -1)
			s[tx][ty] = 'O';
		flag = judge('O');
		if(flag)
		{
			printf("O won\n");
			continue;
		}
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 4; j++)
				if(s[i][j] == '.')
					break;
			if(j != 4)
				break;
		}
		if(i == 4)
		{
			printf("Draw\n");
			continue;
		}
		printf("Game has not completed\n");
	}
	return 0;
}

