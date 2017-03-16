#include<stdio.h>

int N;
int data[ 1003 ][ 2 ];
bool check[ 1003 ][ 2 ];

int main( ) 
{
	int T;
	
	scanf("%d", &T );
	for( int tt = 1; tt <= T; tt ++ ) 
	{
		scanf( "%d", &N );


		for( int i = 1; i <= N; i ++ )
		{
			scanf( "%d %d", &data[ i ][ 0 ], &data[ i ][ 1 ] );
			check[ i ][ 0 ] = check[ i ][ 1 ] = false;
		}


		int now = 0;
		int turn = 0;

		while( true ) 
		{
			int type = 0;
			int k = 0;

			for( int i = 1; i <= N; i ++ ) 
			{
				if( now >= data[ i ][ 1 ] && check[ i ][ 0 ] == false ) 
				{
					type = 3;
					k = i;
				}
				else if( type != 3 && now >= data[ i ][ 1 ] && check[ i ][ 1 ] == false ) 
				{
					type = 2;
					k = i;
				}
				if( type < 2 && now >= data[ i ][ 0 ] && check[ i ][ 0 ] == false )
				{
					if( k != 0 ) 
					{
						if( data[ i ][ 1 ] > data[ k ][ 1 ] ) 
							k = i;
					}
					else k = i;
					type = 1;
				}
			}

			if( type == 3 )
			{
				now += 2;
				check[ k ][ 0 ] = check[ k ][ 1 ] = true;
			}
			else if( type != 0 )
			{
				now ++;
				check[ k ][ type - 1 ] = true;
			}
			else break;
			turn ++;
		}
		printf( "Case #%d: ", tt );
		if( now != N * 2 ) 
		{
			printf("Too Bad\n" );
		}
		else
		{
			printf("%d\n", turn );
		}

	}
	return 0;
}
