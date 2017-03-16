#include "stdio.h"

const int numWinning = 10;
int winning[numWinning][4] = {
	{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15},
	{0, 4, 8, 12}, {1,5,9,13}, {2,6,10,14}, {3,7,11,15},
	{0,5,10,15}, {3,6,9,12}};
	
enum Result
{
	XWON,
	OWON,
	DRAW,
	NOTOVER
};

int main(int argc,char *argv[])
{
	(void) argc;
	(void) argv;
	int numTests;
	char board[16];
	
	scanf("%d", &numTests);
	
	for(int i = 0;i < numTests;i++)
	{
		int dotCount = 0;
		for(int j = 0;j < 16;j++)
		{
			scanf(" %c ", board + j);
			if(board[j] == '.')
			{
				dotCount++;
			}
		}
		
		Result result = NOTOVER;
		if(dotCount == 0)
		{
			result = DRAW;
		}
		
		for(int j = 0;j < numWinning;j++)
		{
			int xcount = 0;
			int ocount = 0;
			int tcount = 0;
			for(int k = 0;k < 4;k++)
			{
				switch(board[winning[j][k]])
				{
				case 'T':
					tcount++;
					break;
				case 'O':
					ocount++;
					break;
				case 'X':
					xcount++;
					break;
				}
			}
			if(xcount == 4 || (xcount == 3 && tcount == 1))
			{
				result = XWON;
				break;
			}
			else if(ocount == 4 || (ocount == 3 && tcount == 1))
			{
				result = OWON;
				break;
			}
		}
		
		printf("Case #%d: ", i+1);
		switch(result)
		{
		case XWON:
			printf("X won");
				break;
		case OWON:
			printf("O won");
				break;
		case NOTOVER:
			printf("Game has not completed");
				break;
		case DRAW:
			printf("Draw");
				break;
		}
		printf("\n");
	}
	
	return 0;
}


