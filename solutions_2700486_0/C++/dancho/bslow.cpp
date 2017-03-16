#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, x, y;
int lx, rx;
int d;

bool us[5020][5020];
double com[5020][5020];

double all, good;

void rec( int rem, int hl, int hr, double c )
{
	if ( rem == 0 )
	{
		all += c;
		if ( hr > y )
			good += c;
	}
	else
	{
		if ( hl == d )
			rec( rem-1, hl, hr+1, c );
		else if ( hr == d )
			rec( rem-1, hl+1, hr, c );
		else
		{
			rec( rem-1, hl, hr+1, c/2 );
			rec( rem-1, hl+1, hr, c/2 );
		}
	}
}

int main()
{
	int t, T;
	int i, k;
	memset( us, 0, sizeof( us ) );
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d %d", &n, &x, &y );
		k = 1;
		n--;
		rx = 0;
		while ( n >= 4*k+1 )
		{
			n -= (4*k+1);
			k++;
			rx += 2;
		}
		
		if ( x < 0 ) x = -x;
		
		all = 0;
		good = 0;
		if ( x + y > rx + 2 )
		{
			printf( "Case #%d: %.8lf\n", t, 0.0 );
			continue;
		}
		if ( x + y <= rx )
		{
			printf( "Case #%d: %.8lf\n", t, 1.0 );
			continue;
		}
		
		d = 2*k;
		rec( n, 0, 0, 1 );
		fprintf( stderr, "%lf %lf\n", all, good );
		printf( "Case #%d: %.8lf\n", t, good/all );
	}
	return 0;
}
