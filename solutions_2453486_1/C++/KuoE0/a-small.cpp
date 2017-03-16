#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


bool checkFull( char board[][ 10 ] ) {
	
	for ( int i = 0; i < 4; ++i ) 
		for ( int j = 0; j < 4; ++j )
			if ( board[ i ][ j ] == '.' )
				return false;
	return true;
}

bool checkRowCol( char board[][ 10 ], char k, int rc, bool dir ) {
	
	int cnt = 0, T = 0;

	for ( int i = 0; i < 4; ++i ) {
		char c = board[ dir ? i : rc ][ dir ? rc : i ];
		cnt += c == k ? 1 : 0;
		T += c == 'T' ? 1 : 0;
	}
	return cnt == 4 || ( cnt == 3 && T == 1 );
}

bool checkDiagonal( char board[][ 10 ], char k, bool dir ) {
	
	int cnt = 0, T = 0;

	for ( int i = 0; i < 4; ++i ) {
		int c = board[ i ][ dir ? 3 - i : i ];

		cnt += c == k ? 1 : 0;
		T += c == 'T' ? 1 : 0;
	}
	return cnt == 4 || ( cnt == 3 && T == 1 );
}


bool checkWin( char board[][ 10 ], char k ) {
	for ( int i = 0; i < 4; ++i )
		if ( checkRowCol( board, k, i, 0 ) || checkRowCol( board, k, i, 1 ) )
			return true;
	for ( int i = 0; i < 2; ++i )
		if ( checkDiagonal( board, k, i ) )
			return true;
	return false;
}

int main() {

	int t;

	scanf( "%d", &t );

	for ( int test = 0; test < t; ++test ) {

		char board[ 4 ][ 10 ];

		for ( int i = 0; i < 4; ++i ) 
			scanf( "%s", board[ i ] );

		if ( checkWin( board, 'X' ) )
			printf( "Case #%d: X won\n", test + 1 );
		else if ( checkWin( board, 'O' ) )
			printf( "Case #%d: O won\n", test + 1 );
		else if ( !checkFull( board ) )
			printf( "Case #%d: Game has not completed\n", test + 1 );
		else 
			printf( "Case #%d: Draw\n", test + 1 );
	}
	return 0;
}
