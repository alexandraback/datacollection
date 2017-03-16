#include <cstdio>

using namespace std;

#define L 8
#define N 10000005

bool seen[N];
int T, ten[L], next[N];

int main()
{
	ten[0] = 1;
	for( int i = 1; i < L; i++ ) ten[i] = ten[i-1] * 10;

	for( int pow = 0; pow + 1 < L; pow++ ) for( int i = ten[pow]; i < ten[pow+1]; i++ )
	{
		int j = i;
		do j = ( ( 10 * j ) % ten[pow+1] ) + ( j / ten[pow] );
		while( j < ten[pow] );
		next[i] = j;
	}

	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ )
	{
		int a, b, ans = 0;
		scanf( "%d%d", &a, &b );
		for( int i = a; i <= b; i++ ) seen[i] = false;
		for( int i = a; i <= b; i++ ) if( !seen[i] )
		{
			int j = i, cnt = 0;
			do
			{
				if( a <= j && j <= b ) cnt++;
				seen[j] = true;
				j = next[j];
			}
			while( j != i );
			ans += cnt * ( cnt - 1 ) / 2;
		}
		printf( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
