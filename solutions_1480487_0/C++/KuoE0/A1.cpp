#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>


using namespace std;


int sgn( double x ) {
	return fabs( x ) < 1e-6 ? 0 : x > 0 ? 1 : -1;
}

int main() {

	int test;

	scanf( "%d", &test );


	for ( int t = 0; t <test; ++t ) {

		int n;
		scanf( "%d", &n );

		int x, totalsum = 0;

		vector< int > num;
		vector< double > ret( n );
		vector< bool > found( n, 0 );

		for ( int i = 0; i < n; ++i ) {
			scanf( "%d", &x );
			num.push_back( x );
			totalsum += x ;
		}


		while ( 1 ) {

			int cnt = 0, sum = 0;
			vector< pair< pair< int, int >, double > > temp;

			for ( int i = 0; i < num.size(); ++i ) {
				if ( found[ i ] )
					continue;

				temp.push_back( pair< pair< int, int >, double >( pair< int, int >( i, num[ i ] ), 0 ) );
				sum += num[ i ];
			}

			if ( !temp.size() )
				break;

			for ( int i = 0; i < temp.size(); ++i ) {
				if ( !sum ) {
					temp[ i ].second = double( 1 ) / temp.size() * 100;
					continue;
				}
				temp[ i ].second = ( ( double( sum ) + totalsum ) / temp.size() - temp[ i ].first.second ) / totalsum * 100;
			}

			for ( int i = 0; i < temp.size(); ++i ) {
				if ( sgn( temp[ i ].second ) <= 0 ) {
					found[ temp[ i ].first.first ] = 1;
					ret[ temp[ i ].first.first ] = 0;
					++cnt;
				}
			}

			if ( !cnt ) {
				for ( int i = 0; i < temp.size(); ++i ) {
					ret[ temp[ i ].first.first ] = temp[ i ].second;
					found[ temp[ i ].first.first ] = 1;
				}
				break;
			}
		}

		printf( "Case #%d: ", t + 1 );
		for ( int i = 0; i < n; ++i ) {
			if ( i )
				putchar( ' ');
			printf( "%.6lf", ret[ i ] );
		}
		puts( "" );

	}

	return 0;
}
