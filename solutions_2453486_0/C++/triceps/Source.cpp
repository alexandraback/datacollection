#include <iostream>
#include <string>

using namespace std;

int check_line( const char line[4] )
{
	bool Owin = true, Xwin = true;
	for ( int j = 0; j < 4; j++ ) {
		if ( line[j]=='.' ) {
			Owin = Xwin = false;
			break;
		}
		if ( line[j] == 'O' ) Xwin = false;
		if ( line[j] == 'X' ) Owin = false;
	}
	if ( Xwin ) return 0;
	if ( Owin ) return 1;
	return -1;
}

int check( const string board[4] )
{
	for ( int i = 0; i < 4; i++ ) {
		int f = check_line( board[i].c_str() );
		if ( f >= 0 ) return f;
		char line[4] = { board[0][i], board[1][i], board[2][i], board[3][i] };
		f = check_line( line );
		if ( f >= 0 ) return f;
	}
	{
		char line[4] = { board[0][0], board[1][1], board[2][2], board[3][3] };
		int f = check_line( line );
		if ( f >= 0 ) return f;
	}
	{
		char line[4] = { board[0][3], board[1][2], board[2][1], board[3][0] };
		int f = check_line( line );
		if ( f >= 0 ) return f;
	}

	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			if ( board[i][j] == '.' ) {
				return -1;
			}
		}
	}
	return 2;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 0; t < T; t++ ) {
		string board[4];
		for ( int i = 0; i < 4; i++ ) {
			cin >> board[i];
		}

		int f = check(board);
		if ( f == 0 ) printf( "Case #%d: X won\n", t+1 );
		if ( f == 1 ) printf( "Case #%d: O won\n", t+1 );
		if ( f == 2 ) printf( "Case #%d: Draw\n", t+1 );
		if ( f == -1 ) printf( "Case #%d: Game has not completed\n", t+1 );
	}
	return 0;
}
