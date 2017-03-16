#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


double MIN;
vector< double > p;
int a, b;

vector< pair< double, int > > p2;

void BT( int x, int mistake, double now ) {

	if ( x == a ) {

		p2.push_back( pair< double, int >( now, mistake ) );
		return;
	}

	BT( x + 1, mistake, now * p[ x ] );
	BT( x + 1, min( x, mistake ), now * ( 1 - p[ x ] ) );
}

int main() {


	int test;
	scanf( "%d", &test );

	for ( int t = 1; t <= test; ++t ) {
		scanf( "%d %d", &a, &b );


		p.clear();
		p2.clear();
		for ( int i = 0; i < a; ++i ) {
			double x;
			scanf( "%lf", &x );
			p.push_back( x );
		}

		BT( 0, 1e9, 1 );

		MIN = 1e9;

		double temp = 0;

		for ( int i = 0; i < p2.size(); ++i ) {
			if ( p2[ i ].second == (int)1e9 ) {
				temp += p2[ i ].first * ( b - a + 1 );
			}
			else {
				temp += p2[ i ].first * ( b - a + 1 + b + 1 );
			}
		}

		MIN = min( MIN, temp );


		temp = 0;

		int minMis = 1e9;
		for ( int i = 0; i < p2.size(); ++i ) {
			minMis = min( minMis, p2[ i ].second );
		}

		for ( int i = 0; i < p2.size(); ++i ) {
			temp += p2[ i ].first * ( a - minMis + ( b - minMis + 1 ) );
		}
		MIN = min( MIN, temp );

		for ( int i = 0; i < a; ++i ) {
			temp = 0;
			for ( int j = 0; j < p2.size(); ++j ) {
				if ( i <= p2[ j ].second ) {
					temp += p2[ j ].first * ( a - i + ( b - i + 1 ) );
				}
				else {
					temp += p2[ j ].first * ( a - i + ( b - i + 1 ) + b + 1 );
				}
			}
			MIN = min( MIN, temp );

		}


		temp = 0;
		for ( int i = 0; i < p2.size(); ++i ) {
			temp += p2[ i ].first * ( 1 + b + 1 );
		}

		MIN = min( MIN, temp );

		printf( "Case #%d: %.6lf\n", t, MIN );
	}
	return 0;
}
