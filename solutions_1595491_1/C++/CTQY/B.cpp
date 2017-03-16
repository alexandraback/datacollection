#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int score[100];

int main()
{
	freopen( "B.in", "r", stdin );
	freopen( "B.out", "w", stdout );

	int t;
	int n, s, p;
	int pb, b, b2, rs;
	int i, j;

	scanf( "%d", &t );
	for( i = 1; i <= t; ++i )
		{
		scanf( "%d%d%d", &n, &s, &p );
		pb = max( p - 1, 0 );
		b = p + pb * 2;
		pb = max( p - 2, 0 );
		b2 = p + pb * 2;
		for( j = 0; j < n; ++j )
			{
			scanf( "%d", &score[j] );
			}//end for
		sort( score, score + n, greater<int>() );
		for( j = 0; j < n && score[j] >= b; ++j );//end for
		for( rs = 0; j < n && rs < s && score[j] >= b2; ++j, ++rs );//end for
		printf( "Case #%d: %d\n", i, j );
		}//end for
	return 0;
}
