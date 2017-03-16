#include <stdio.h>
char a[5][5];
void solve ( ) {
	int i, j, x, o, t, point;
	for ( i = 0; i < 4; ++i ) {
		x = o = t = point = 0;
		for ( j = 0; j < 4; ++j )
			switch ( a[i][j] ) {
				case 'X': ++x;
						  break;
				case 'O': ++o;
						  break;
				case 'T': ++t;
						  break;
				case '.': ++point;
						  break;
			}
		if ( point ) continue;
		else if ( x + t == 4 ) {
			printf ( " X won\n" );
			return;
		}
		else if ( o + t == 4 ) {
			printf ( " O won\n" );
			return;
		}
	}
	for ( i = 0; i < 4; ++i ) {
		x = o = t = point = 0;
		for ( j = 0; j < 4; ++j )
			switch ( a[j][i] ) {
				case 'X': ++x;
						  break;
				case 'O': ++o;
						  break;
				case 'T': ++t;
						  break;
				case '.': ++point;
						  break;
			}
		if ( point ) continue;
		else if ( x + t == 4 ) {
			printf ( " X won\n" );
			return;
		}
		else if ( o + t == 4 ) {
			printf ( " O won\n" );
			return;
		}
	}
	x = o = t = point = 0;
	for ( i = 0; i < 4; ++i ) {
		switch ( a[i][i] ) {
			case 'X': ++x;
					  break;
			case 'O': ++o;
					  break;
			case 'T': ++t;
					  break;
			case '.': ++point;
					  break;
		}
		//printf ( "x=%d o=%d t=%d point=%d\n", x, o, t, point );
		if ( point ) continue;
		else if ( x + t == 4 ) {
			printf ( " X won\n" );
			return;
		}
		else if ( o + t == 4 ) {
			printf ( " O won\n" );
			return;
		}
	}
	x = o = t = point = 0;
	for ( i = 0; i < 4; ++i ) {
		switch ( a[i][3-i] ) {
			case 'X': ++x;
					  break;
			case 'O': ++o;
					  break;
			case 'T': ++t;
					  break;
			case '.': ++point;
					  break;
		}
		if ( point ) continue;
		else if ( x + t == 4 ) {
			printf ( " X won\n" );
			return;
		}
		else if ( o + t == 4 ) {
			printf ( " O won\n" );
			return;
		}
	}
	for ( i = 0; i < 4; ++i ) {
		for ( j = 0; j < 4; ++j )
			if ( a[i][j] == '.' ) {
				printf ( " Game has not completed\n" );
				return;
			}
	}
	printf ( " Draw\n" );
	return;
}
int main ( ) {
	int T;
	scanf ( "%d", &T );
	for ( int i = 0; i < T; ++i ) {
		printf ( "Case #%d: ", i + 1 );
		for ( int j = 0; j < 4; ++j ) scanf ( "%s", a[j] );
		//for ( int x = 0; x < 4; ++x ) { for ( int y = 0; y < 4; ++y ) printf ( "%c", a[x][y] ); printf ( "\n" ); }
		solve ( );
	}
}
