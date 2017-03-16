#include <iostream>
#include <string>

using namespace std;

string a[4];

int check_winner( char x ) {
	// rows
	for( int i = 0; i < 4; ++i ) {
		int ok = 1;
		for( int j = 0; j < 4; ++j ) {
			if( a[i][j] != x && a[i][j] != 'T' ) {
				ok = 0;
				break;
			}
		}
		if( ok ) return 1;
	}
	
	// cols
	for( int j = 0; j < 4; ++j ) {
		int ok = 1;
		for( int i = 0; i < 4; ++i ) {
			if( a[i][j] != x && a[i][j] != 'T' ) {
				ok = 0;
				break;
			}
		}
		if( ok ) return 1;
	}
	
	// diag1
	int ok = 1;
	for( int i = 0; i < 4; ++i ) {
		if( a[i][i] != x && a[i][i] != 'T' ) {
			ok = 0;
			break;
		}
	}
	if( ok ) return 1;
	
	// diag2
	ok = 1;
	for( int i = 0; i < 4; ++i ) {
		if( a[i][3-i] != x && a[i][3-i] != 'T' ) {
			ok = 0;
			break;
		}
	}
	return ok;
}

int main() {
	int T;
	cin >> T;
	for( int c = 1; c <= T; ++c ) {
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		
		cout << "Case #" << c << ": ";
		
		if( check_winner('X') ) {
			cout << "X won\n";
			continue;
		}
		if( check_winner( 'O' ) ) {
			cout << "O won\n";
			continue;
		}
		for( int i = 0; i < 4; ++i ) {
			for( int j =0 ; j < 4; ++j ) {
				if( a[i][j] == '.' ) goto notcompleted;
			}
		}
		cout << "Draw\n";
		continue;
	notcompleted:
		cout << "Game has not completed\n";
	}
	return 0;
}
