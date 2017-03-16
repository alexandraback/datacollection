#include <cstdio>
#include <cstring>

int n;
int a[1024], b[1024];
int usa[1024], usb[1024];

int main()
{
	int t, T;
	int i, k;
	int x;
	int tr;
	
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d", &n );
		for ( i = 1; i <= n; i++ )
		{
			scanf( "%d %d", &a[i], &b[i] );
		}
		
		a[i] = b[i] = 0;
		
		memset( usa, 0, sizeof( usa ) );
		memset( usb, 0, sizeof( usb ) );
		tr = 0;
		x = 0;
		
		while ( x < 2*n )
		{
			for ( i = 1; i <= n; i++ )
			{
				if ( ( usb[i] == 0 ) && ( x >= b[i] ) )
				{
					x = x + 2 - usa[i];
					tr++;
					usb[i] = 1;
					usa[i] = 1;
					break;
				}
			}
			if ( i <= n ) continue;
			
			k = 0;
			for ( i = 1; i <= n; i++ )
			{
				if ( ( usa[i] == 0 ) && ( x >= a[i] ) )
				{
					if ( b[i] > b[k] )
					{
						k = i;
					}
				}
			}
			if ( k != 0 )
			{
					x++;
					tr++;
					usa[k] = 1;
			}
			else
				break;
		}
		
		if ( x < 2*n )
			printf( "Case #%d: Too Bad\n", t );
		else
			printf( "Case #%d: %d\n", t, tr );
	}
	return 0;
}
