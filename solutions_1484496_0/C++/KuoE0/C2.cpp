#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

vector< int > num, s1, s2;
bool found = 0;
long long int cnt1, cnt2;

void BT( int now ) {

	if ( found )
		return;
	if ( cnt1 && cnt1 == cnt2 ) {
		for ( int i = 0; i < s1.size(); ++i ) {
			if ( i )
				putchar( ' ' );
			printf( "%d", s1[ i ] );
		}
		puts( "" );
		for ( int i = 0; i < s2.size(); ++i ) {
			if ( i )
				putchar( ' ' );
			printf( "%d", s2[ i ] );
		}
		puts( "" );
		found = 1;
		return;
	}

	if ( now == num.size() )
		return;


	BT( now + 1 );
	s1.push_back( num[ now ] );
	cnt1 += num[ now ];
	BT( now + 1 );
	cnt1 -= num[ now ];
	s1.pop_back();
	s2.push_back( num[ now ] );
	cnt2 += num[ now ];
	BT( now + 1 );
	cnt2 -= num[ now ];
	s2.pop_back();
}

int	main() {
	
	int test;
	scanf( "%d", &test );

	for ( int t = 0; t < test; ++t ) {

		int n;

		num = s1 = s2 = vector< int >();
		scanf( "%d", &n );

		for ( int i = 0; i < n; ++i ) {
			int x;
			scanf( "%d", &x );
			num.push_back( x );
		}

		printf( "Case #%d:\n", t + 1 );
		found = 0;
		cnt1 = cnt2 = 0;
		BT( 0 );
		if ( !found ) 
			puts( "Impossible" );
	}
	return 0;
}
