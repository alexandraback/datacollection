#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool ispal( long long x )
{
	char str[256];
	sprintf( str, "%lld", x );
	int n = strlen( str )-1;
	int i, j;
	i = 0; j = n;
	while ( i < j )
	{
		if ( str[i] != str[j] )
			return 0;
		i++;
		j--;
	}
	return true;
}

long long pcnt[20000200];

int main()
{
	int t, T;
	long long k;
	long long i;
	
	
	pcnt[0] = 0;
	for ( i = 1; i <= 20000000; i++ )
	{
		if ( ispal( i ) && ispal( i*i ) )
		{
			pcnt[i] = pcnt[i-1] + 1;
		}
		else
			pcnt[i] = pcnt[i-1];
	}
	
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		long long a, b;
		scanf( "%lld %lld", &a, &b );
		
		k = (long long) sqrt( a );
		if ( k*k == a )
			printf( "Case #%d: %lld\n", t, pcnt[ (int) sqrt( b ) ] - pcnt[ k - 1 ] );
		else
			printf( "Case #%d: %lld\n", t, pcnt[ (int) sqrt( b ) ] - pcnt[ k ] );
	}
	return 0;
}

