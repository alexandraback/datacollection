#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>

using namespace std;
#define BOARD_SIZE 4
#define MAX_TEST_CASES 1000
char *outString[] = 
					{
						"X won",
						"O won",
						"Draw",
						"Game has not completed"
					};

//all 3 below functions return NULL, if no winner is found and count is 0.
int checkRowAndReturnWinner(char board[BOARD_SIZE], char* winner)
{
	assert(winner);
	*winner = 0;
	int X=0, O=0, T=0, empty=0;
	for(int i =0; i < BOARD_SIZE; i++)
	{
		if(board[i] == 'X')
			X++;
		else if(board[i] == 'O')
			O++;
		else if((board[i] == 'T'))
			T++;
		else
			empty++;
	}
	if((X==3 && T == 1) || (4 == X))
		*winner = 'X';
	else if((O==3 && T == 1) || (4 == O))
		*winner = 'O';
	return empty;
}

int checkColumnAndReturnWinner(char (*board)[BOARD_SIZE], int index, char* winner)
{
	assert(winner);
	assert(index>=0 && index<=3);
	*winner = 0;
	int X=0, O=0, T=0, empty=0;
	for(int i =0; i < BOARD_SIZE; i++)
	{
		if(board[i][index] == 'X')
			X++;
		else if(board[i][index] == 'O')
			O++;
		else if((board[i][index] == 'T'))
			T++;
		else
			empty++;
	}
	if((X==3 && T == 1) || (4 == X))
		*winner = 'X';
	else if((O==3 && T == 1) || (4 == O))
		*winner = 'O';
	return empty;
}

int checkDiagonalAndReturnWinner(char (*board)[BOARD_SIZE], char* winner)
{
	assert(winner);
	*winner = 0;
	int X=0, O=0, T=0, empty=0;
	//diagonal tilted left
	for(int i =0; i < BOARD_SIZE; i++)
	{
		if(board[i][i] == 'X')
			X++;
		else if(board[i][i] == 'O')
			O++;
		else if((board[i][i] == 'T'))
			T++;
		else
			empty++;
	}
	if((X==3 && T == 1) || (4 == X))
		*winner = 'X';
	else if((O==3 && T == 1) || (4 == O))
		*winner = 'O';
	if(*winner) // if encountered winner, return with empty cell count. Else check other diagonal.
		return empty;
	/////////////////////////////////
	//diagonal tilted right
	X=0, O=0, T=0;
	for(int i =0; i < BOARD_SIZE; i++)
	{
		if(board[i][BOARD_SIZE-1-i] == 'X')
			X++;
		else if(board[i][BOARD_SIZE-1-i] == 'O')
			O++;
		else if((board[i][BOARD_SIZE-1-i] == 'T'))
			T++;
		else
			empty++;
	}
	if((X==3 && T == 1) || (4 == X))
		*winner = 'X';
	else if((O==3 && T == 1) || (4 == O))
		*winner = 'O'; 
	return empty;
}

int gameState(char(*board)[BOARD_SIZE])
{
	int retIndex=-1, empty=0;
	char winner = 0;
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		empty += checkRowAndReturnWinner(board[i], &winner);
		if(!winner)
			empty += checkColumnAndReturnWinner(board, i, &winner);
		if(winner)
			break;
	}
	if(!winner)
		empty += checkDiagonalAndReturnWinner(board, &winner);

	if(winner == 'X')
		retIndex = 0;
	else if(winner == 'O')
		retIndex = 1;
	else if(empty == 0)
		retIndex = 2;
	else
		retIndex = 3;
	return retIndex;
}

void  ticTacToeTomek()
{
	char *inFile = "C:\\Users\\Roopam Singh\\Documents\\Visual Studio 2010\\Projects\\PracticeC++\\InputOutput\\A-small-attempt0.in";
	char *outFile = "C:\\Users\\Roopam Singh\\Documents\\Visual Studio 2010\\Projects\\PracticeC++\\InputOutput\\sampleOutput.txt";
	
	FILE *ifp = fopen(inFile, "r");
	FILE *ofp = fopen(outFile, "w");
	assert(ifp);
	assert(ofp);

	int tcases=0;
	char board[BOARD_SIZE][BOARD_SIZE] = {{'.', '.','.', '.'},};

	fscanf(ifp, "%d\n", &tcases);

	for(int i = 0; i < tcases; i++)
	{
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			assert(4 == fread(board[j], sizeof(char), BOARD_SIZE, ifp));
			fgetc(ifp); //ignore newline after each row of game input
		}
		int output = gameState(board);
		fprintf(ofp, "Case #%d: %s\n", i+1, outString[output]);
		fgetc(ifp); //ignore new line between each input of game board state
	}

	fclose(ifp);
	fclose(ofp);
	return;
}
