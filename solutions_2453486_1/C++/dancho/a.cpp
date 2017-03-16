#include <cstdio>
#include <cstring>

char tic[8][8];

int main()
{
	int t, T;
	int i, j;
	bool winx, wino, hase;
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		for (i = 0; i < 4; i++)
		{
			scanf( "%s", tic[i] );
		}
		
		hase = 0;
		for ( i = 0; i < 4; i++ )
			for ( j = 0; j < 4; j++ )
				if ( tic[i][j] == '.' )
					hase = 1;

		winx = wino = 0;
		for ( i = 0; i < 4; i++ )
		{
			for ( j = 0; j < 4; j++ )
			{
				if ( tic[i][j] == 'O' || tic[i][j] == '.' )
					break;
			}
			if ( j >= 4 )
				winx = 1;

			for ( j = 0; j < 4; j++ )
			{
				if ( tic[j][i] == 'O' || tic[j][i] == '.' )
					break;
			}
			if ( j >= 4 )
				winx = 1;

			for ( j = 0; j < 4; j++ )
			{
				if ( tic[j][j] == 'O' || tic[j][j] == '.' )
					break;
			}
			if ( j >= 4 )
				winx = 1;

			for ( j = 0; j < 4; j++ )
			{
				if ( tic[j][3-j] == 'O' || tic[j][3-j] == '.' )
					break;
			}
			if ( j >= 4 )
				winx = 1;
				
			for ( j = 0; j < 4; j++ )
			{
				if ( tic[i][j] == 'X' || tic[i][j] == '.' )
					break;
			}
			if ( j >= 4 )
				wino = 1;

			for ( j = 0; j < 4; j++ )
			{
				if ( tic[j][i] == 'X' || tic[j][i] == '.' )
					break;
			}
			if ( j >= 4 )
				wino = 1;

			for ( j = 0; j < 4; j++ )
			{
				if ( tic[j][j] == 'X' || tic[j][j] == '.' )
					break;
			}
			if ( j >= 4 )
				wino = 1;

			for ( j = 0; j < 4; j++ )
			{
				if ( tic[j][3-j] == 'X' || tic[j][3-j] == '.' )
					break;
			}
			if ( j >= 4 )
				wino = 1;
		}
		
		printf( "Case #%d: ", t );
		if ( winx )
			printf( "X won\n" );
		else if ( wino )
			printf( "O won\n" );
		else if ( hase )
			printf( "Game has not completed\n" );
		else
			printf( "Draw\n" );
	}
	return 0;
}
