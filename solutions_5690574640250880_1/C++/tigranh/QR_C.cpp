
#include <iostream>
#include <cassert>

using namespace std;

void output_mat( int r, int c, char mat[ 100 ][ 100 ] )
{
	for ( int i = 0; i < r; ++i ) {
		for ( int j = 0; j < c; ++j )
			cout.put( mat[ i ][ j ] );
		cout << endl;
	}
}

bool solve( int r, int c, int m, char mat[ 100 ][ 100 ] )
{
	if ( r < c ) {
		if ( ! solve( c, r, m, mat ) )
			return false;
		int rc = std::max( r, c );
		for ( int i = 0; i < rc; ++i )
			for ( int j = i + 1; j < rc; ++j )
				std::swap( mat[ i ][ j ], mat[ j ][ i ] );
		return true;
	}
	if ( c == 1 ) {
		int i;
		for ( i = 0; i < m; ++i )
			mat[ i ][ 0 ] = '*';
		for ( ; i < r - 1; ++i )
			mat[ i ][ 0 ] = '.';
		mat[ r - 1 ][ 0 ] = 'c';
		return true;
	}
	if ( c == 2 ) {
		int free = r * c - m;
		if ( free == 1 ) {
			for ( int i = 0; i < r; ++i )
				mat[ i ][ 0 ] = mat[ i ][ 1 ] = '*';
			mat[ r - 1 ][ 1 ] = 'c';
			return true;
		}
		if ( m % 2 == 1 )
			return false;
		if ( free == 2 )
			return false;
		int i;
		for ( i = 0; i < m/2; ++i )
			mat[ i ][ 0 ] = mat[ i ][ 1 ] = '*';
		for ( ; i < r; ++i )
			mat[ i ][ 0 ] = mat[ i ][ 1 ] = '.';
		mat[ r - 1 ][ 1 ] = 'c';
		return true;
	}
	int free = r * c - m;
	if ( free == 7 )
		return false;
	if ( free == 5 )
		return false;
	if ( free == 3 )
		return false;
	if ( free == 2 )
		return false;
	int i, j;
	int remaining = m;
	for ( i = 0; i < r; ++i )
		for ( j = 0; j < c; ++j )
			mat[ i ][ j ] = '.';
	for ( i = 0; i < r - 2 && remaining > 0; ++i ) {
		for ( j = 0; j < c - 2 && remaining > 0; ++j ) {
			mat[ i ][ j ] = '*';
			--remaining;
		}
	}
	for ( i = 0; i < r - 3 && remaining > 0; ++i ) {
		mat[ i ][ c - 2 ] = mat[ i ][ c - 1 ] = '*';
		mat[ r - 3 ][ c - 3 ] = '.';
		--remaining;
		if ( remaining == 0 )
			break;
		mat[ r - 3 ][ c - 3 ] = '*';
		--remaining;
	}
	for ( j = 0; j < c - 3 && remaining > 0; ++j ) {
		mat[ r - 2 ][ j ] = mat[ r - 1 ][ j ] = '*';
		mat[ r - 3 ][ c - 3 ] = '.';
		--remaining;
		if ( remaining == 0 )
			break;
		mat[ r - 3 ][ c - 3 ] = '*';
		--remaining;
	}
	mat[ r - 1 ][ c - 1 ] = 'c';
	if ( remaining == 0 )
		return true;
	assert( remaining >= 2 );
	mat[ r - 3 ][ c - 2 ] = mat[ r - 3 ][ c - 1 ] = '*';
	remaining -= 2;
	if ( remaining == 0 )
		return true;
	assert( remaining >= 2 );
	mat[ r - 2 ][ c - 3 ] = mat[ r - 1 ][ c - 3 ] = '*';
	remaining -= 2;
	if ( remaining == 0 )
		return true;
	assert( remaining == 3 );
	mat[ r - 2 ][ c - 2 ] = mat[ r - 1 ][ c - 2 ] = mat[ r - 2 ][ c - 1 ] = '*';
	remaining -= 3;
	assert( remaining == 0 );
	return true;
}

int main()
{
	int T;
	cin >> T;
	char mat[ 100 ][ 100 ];
	for ( int t = 1; t <= T; ++t ) {
		int r, c, m;
		cin >> r >> c >> m;
		cout << "Case #" << t << ":" << endl;
		if ( solve( r, c, m, mat ) )
			output_mat( r, c, mat );
		else
			cout << "Impossible" << endl;
	}
}
