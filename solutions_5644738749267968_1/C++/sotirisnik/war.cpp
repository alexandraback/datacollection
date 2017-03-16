#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>

#define MAXN 1001

using namespace std;

int tests, n, q1, q2;
double Naomi[MAXN], Ken[MAXN];

multiset <double> Nam_set, Ken_set;
multiset <double>::iterator Nam_iterator, Ken_iterator;

int main( ) {

	scanf( "%d", &tests );

	for ( int T = 1; T <= tests; ++T  ) {
		scanf( "%d", &n );

		Nam_set.clear();
		Ken_set.clear();

		for ( int i = 1; i <= n; ++i ) {
			scanf( "%lf", &Naomi[i] );
			Nam_set.insert( Naomi[i] );
		}

		for ( int i = 1; i <= n; ++i ) {
			scanf( "%lf", &Ken[i] );
			Ken_set.insert( Ken[i] );
		}

		/*
		sort( Naomi+1, Naomi+n+1 );
		sort( Ken+1, Ken+n+1 );

		for ( int i = 1; i <= n; ++i )
			printf( "%lf ", Naomi[i] );
		putchar( '\n' );

		for ( int i = 1; i <= n; ++i )
			printf( "%lf ", Ken[i] );
		putchar( '\n' );
		*/

		q2 = n;

		for ( int i = 1; i <= n; ++i ) {
			Nam_iterator = Nam_set.begin();
			Ken_iterator = Ken_set.lower_bound( *Nam_iterator );

			if ( Ken_iterator == Ken_set.end() ) {
				break;
			}

			//printf( "%lf %lf\n", *Nam_iterator, *Ken_iterator );

			if ( *Ken_iterator > *Nam_iterator ) {
				--q2;
			}

			Nam_set.erase( Nam_set.find( *Nam_iterator ) );
			Ken_set.erase( Ken_set.find( *Ken_iterator ) );

		}

		Nam_set.clear();
		Ken_set.clear();

		for ( int i = 1; i <= n; ++i ) {
			Nam_set.insert( Naomi[i] );
		}

		for ( int i = 1; i <= n; ++i ) {
			Ken_set.insert( Ken[i] );
		}

		q1 = 0;

		for ( int i = 1; i <= n; ++i ) {
			Ken_iterator = Ken_set.begin();
			Nam_iterator = Nam_set.lower_bound( *Ken_iterator );

			if ( Nam_iterator == Nam_set.end() ) {
				break;
			}

			//printf( "%lf %lf\n", *Nam_iterator, *Ken_iterator );

			if ( *Ken_iterator < *Nam_iterator ) {
				++q1;
			}

			Nam_set.erase( Nam_set.find( *Nam_iterator ) );
			Ken_set.erase( Ken_set.find( *Ken_iterator ) );

		}

		printf( "Case #%d: %d %d\n", T, q1, q2 );

	}

	return 0;

}
