#include <iostream>
#include <stdio.h>

using namespace std;

char board[4][5];

int check(char v , int &c3)
{
	int c1,c2,i,j;
	for( c3 = i = 0; i < 4; i++)
	{
		for( c1 = c2 = j = 0; j < 4; j++)
		{
			c1 += board[i][j] == v || board[i][j] == 'T';
			c2 += board[j][i] == v || board[j][i] == 'T';
			c3 += board[i][j] != '.';
		}
		if( c1 == 4 || c2 == 4 ) return 1; 
	}

	for( c1 = c2 = i = 0; i < 4; i++)
	{
		c1 += board[i][i] == v || board[i][i] == 'T';
		c2 += board[i][3-i] == v || board[i][3-i] == 'T';
	}
	if( c1 == 4 || c2 == 4 ) return 1;
	return 0;
}

int main()
{
	int T,cnt,c = 1;
	scanf("%d",&T);
	while(T--)
	{
		for(int i = 0; i < 4; i++) scanf("%s",board[i]);
		printf("Case #%d: ",c++);
		if( check('X',cnt) ) printf("X won\n");
		else if( check('O',cnt) ) printf("O won\n");
		else if( cnt == 16 ) printf("Draw\n");
		else printf("Game has not completed\n");
	}

	return 0;
}