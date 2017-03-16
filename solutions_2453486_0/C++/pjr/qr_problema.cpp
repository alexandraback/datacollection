#include <stdio.h>
#include <string.h>

#define M 5

FILE *fin = fopen( "input.txt", "r" );
FILE *fout = fopen( "output.txt", "w" );

char map[M][M];
int mapCount[M][M][2];
bool dotFlag = false;
bool oWin = false;
bool xWin = false;

void input();
void output( int t );
void process();

int main()
{
	int i, T;

	fscanf( fin, "%d", &T );
	for ( i=0; i<T; i++ )
	{
		input();
		process();
		output(i);
	}
	return 0;
}

void input()
{
	int i;
	for ( i=0; i<4; i++ )
	{
		fscanf( fin, "%s", &map[i] );
	}
}
void process()
{
	int i, j;
	int tY=-1, tX;
	bool checkFlag;

	dotFlag = false;
	oWin = false;
	xWin = false;

	for ( i=0; i<4; i++ )
	{
		for ( j=0; j<4; j++ )
		{
			if ( map[i][j] == 'T' ){
				tY = i;
				tX = j;
			}
			else if ( !dotFlag && map[i][j] == '.' )
			{
				dotFlag = true;
			}
		}
	}

	if ( tY != -1 ) map[tY][tX] = 'O';
	for ( i=0; i<4; i++ )
	{
		if ( strncmp ( map[i], "OOOO", 4) == 0 )
		{
			oWin = true;
			break;
		}

		checkFlag = true;
		for ( j=0; j<4; j++ )
		{
			if ( map[j][i] != 'O' )
			{
				checkFlag = false;
				break;
			}
		}
		if ( checkFlag )
		{
			oWin = true;
			break;
		}
	}
	if ( !oWin )
	{
		if ( map[0][0]+map[1][1]+map[2][2]+map[3][3] == int('O')*4 ||
			map[0][3]+map[1][2]+map[2][1]+map[3][0] == int('O')*4 )
		{
			oWin = true;
		}
	}



	if ( tY != -1 ) map[tY][tX] = 'X';
	for ( i=0; i<4; i++ )
	{
		if ( strncmp ( map[i], "XXXX", 4) == 0 )
		{
			xWin = true;
			break;
		}

		checkFlag = true;
		for ( j=0; j<4; j++ )
		{
			if ( map[j][i] != 'X' )
			{
				checkFlag = false;
				break;
			}
		}
		if ( checkFlag )
		{
			xWin = true;
			break;
		}
	}
	if ( !xWin )
	{
		if ( map[0][0]+map[1][1]+map[2][2]+map[3][3] == int('X')*4 ||
			map[0][3]+map[1][2]+map[2][1]+map[3][0] == int('X')*4 )
		{
			xWin = true;
		}
	}
}
void output( int t )
{
	fprintf( fout, "Case #%d: ", t+1 );
	if ( oWin )
	{
		fprintf( fout, "O won\n");
		return;
	}
	if ( xWin )
	{
		fprintf( fout, "X won\n");
		return;
	}
	if ( dotFlag )
	{
		fprintf( fout, "Game has not completed\n");
		return;
	}
	fprintf( fout, "Draw\n");
}