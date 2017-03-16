#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char g[110][110];
bool judge1(char f)
{
	if(g[0][0] != f && g[0][0] != 'T')
		return false;
	if(g[1][1] != f && g[1][1] != 'T')
		return false;
	if(g[2][2] != f && g[2][2] != 'T')
		return false;
	if(g[3][3] != f && g[3][3] != 'T')
		return false;
	return true;
}
bool judge2(char f)
{
	if(g[0][3] != f && g[0][3] != 'T')
		return false;
	if(g[1][2] != f && g[1][2] != 'T')
		return false;
	if(g[2][1] != f && g[2][1] != 'T')
		return false;
	if(g[3][0] != f && g[3][0] != 'T')
		return false;
	return true;
}
bool judge3(char f)
{
	for(int i=0;i<4;i++)
	{
		bool ok=true;
		for(int j=0;j<4;j++)
			if(g[i][j] != f && g[i][j] != 'T')
				ok=false;
		if(ok)
			return true;
	}
	for(int j=0;j<4;j++)
	{
		bool ok=true;
		for(int i=0;i<4;i++)
			if(g[i][j] != f && g[i][j] != 'T')
				ok=false;
		if(ok)
			return true;
	}
	return false;
}
bool full()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(g[i][j] == '.')
				return false;
	return true;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int cc=1;cc<=cas;cc++)
	{
		printf("Case #%d: ",cc);
		for(int i=0;i<4;i++)
			scanf("%s",g[i]);
		if(judge1('O') || judge2('O') || judge3('O'))
		{
			printf("O won\n");
			continue;
		}
		if(judge1('X') || judge2('X') || judge3('X'))
		{
			printf("X won\n");
			continue;
		}
		if(!full())
			printf("Game has not completed\n");
		else
			printf("Draw\n");
	}
	return 0;
}
/*
6
XXXT
....
OO..
....

XOXT
XXOO
OXOX
XXOO

XOX.
OX..
....
....

OOXX
OXXX
OX.T
O..O

XXXO
..O.
.O..
T...

OXXX
XO..
..O.
...O

 */

