#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int nd;
int a, b, n;
long long sol;

set<int> S;

int rev( int k )
{
	int j = 0;
	while ( k > 0 )
	{
		j = j * 10 + k % 10;
		k = k / 10;
	}
	return j;
}

int rot( int k, int s )
{
//	printf( "ROT %d %d -> ", k, s );
	int ld = 0;
	int l = 1;
	for ( int i = 1; i <= s; i++ )
	{
		ld = ld + (k%10)*l;
		l = l * 10;
		k = k / 10;
	}
	int d = 1;
	while ( d <= k )
	{
		d = d * 10;
	}
//	printf( "(%d %d) ", ld, d );
	k = k + d*ld;
//	printf( "%d\n", k );
	return k;
}

int main()
{
	int t, T;
	int k;
	
//	n = 21300;
//	for ( int i = 1; i <= 6; i++ )
//	{
		//printf( "%d %d -> %d\n", n, i, rot( n, i ) );
	//}
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%d %d", &a, &b );
		k = a; nd = 0;
		while ( k > 0 )
		{
			nd++;
			k = k / 10;
		}
		sol = 0;
		for ( n = a; n <= b; n++ )
		{
			k = n;
			S.clear();
			for ( int i = 1; i < nd; i++ )
			{
				k = rot( n, i );
				if ( ( k >= a ) && ( k <= b ) && ( k > n ) && ( S.find( k ) == S.end() ) )
				{
					S.insert( k );
					sol++;
				}
			}
		}
		printf( "Case #%d: %lld\n", t, sol );
	}
	return 0;
}
