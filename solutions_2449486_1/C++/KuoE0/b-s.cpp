#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool check( vector< int > &row, vector< int > &col, vector< vector< int > > &lawn ) {

	vector< vector< int > > temp( row.size(), vector< int >( col.size(), 0 ) );

	for ( int i = 0; i < row.size(); ++i )
		for ( int j = 0; j < col.size(); ++j )
			if ( min( row[ i ], col[ j ] ) != lawn[ i ][ j ] )
				return false;
	return true;
}

int main() {

	int test;

	scanf( "%d", &test );

	for ( int t = 0; t < test; ++t ) {

		int R, C;

		scanf( "%d %d", &R, &C );

		vector< vector< int > > lawn( R, vector< int >( C, 0 ) );

		for ( int i = 0; i < R; ++i )
			for ( int j = 0; j < C; ++j ) {
				int x;
				scanf( "%d", &x );
				lawn[ i ][ j ] = x;
			}

		vector< int > row( R, 0 ), col( C, 0 );

		for ( int i = 0; i < R; ++i )
			for ( int j = 0; j < C; ++j ) {
				row[ i ] = max( row[ i ], lawn[ i ][ j ] );
				col[ j ] = max( col[ j ], lawn[ i ][ j ] );
			}

		printf( "Case #%d: %s\n", t + 1, check( row, col, lawn ) ? "YES" : "NO" );

	}
	return 0;
}



