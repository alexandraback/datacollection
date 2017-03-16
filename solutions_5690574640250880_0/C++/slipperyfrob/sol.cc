#include <iostream>
using namespace std;

const size_t MAXN = 50;

/*
bool ok( size_t R, size_t C, size_t M, char board[MAXN][MAXN] ) {
	for( size_t i = 0; i < R; ++i )
	for( size_t j = 0; j < C; ++j )
		board[i][j] = '@';
	size_t left = R*C - M;
	if( left == 1 ) {
		for( size_t i = 0; i < R; ++i )
		for( size_t j = 0; j < C; ++j ) {
			board[i][j] = '*';
		}
		board[0][0] = 'c';
		return true;
	}
	if( R == 1 ) {
		for( size_t j = 0; j < C; ++j ) {
			if( left > 0 ) {
				board[0][j] = '.';
				--left;
			}
			else {
				board[0][j] = '*';
			}
		}
		board[0][0] = 'c';
		return true;
	}
	if( (left % 2 == 0 && left >= 4) || (left >= C*2 && left % C != 1) ) {
		for( size_t j = 0; j < C; ++j ) {
			if( left >= 2 ) {
				board[0][j] = board[1][j] = '.';
				left -= 2;
			}
			else {
				board[0][j] = board[1][j] = '*';
			}
		}
		for( size_t i = 2; i < R; ++i )
		for( size_t j = 0; j < C; ++j ) {
			if( left > 0 ) {
				board[i][j] = '.';
				--left;
			}
			else {
				board[i][j] = '*';
			}
		}
		board[0][0] = 'c';
		return true;
	}
	return false;
}
*/

bool ok( size_t R, size_t C, size_t M, char board[MAXN][MAXN] ) {
	size_t left = R*C - M;
	// special cases
	if( R == 1 ) {
		for( size_t j = 0; j < C; ++j )
			if( left > 0 ) { board[0][j] = '.'; --left; }
			else board[0][j] = '*';
		board[0][0] = 'c';
		return true;
	}
	if( C == 1 ) {
		for( size_t i = 0; i < R; ++i )
			if( left > 0 ) { board[i][0] = '.'; --left; }
			else board[i][0] = '*';
		board[0][0] = 'c';
		return true;
	}
	if( left == 0 ) return false;
	if( left == 1 ) {
		for( size_t i = 0; i < R; ++i )
		for( size_t j = 0; j < C; ++j )
			board[i][j] = '*';
		board[0][0] = 'c';
		return true;
	}
	// we can now assume that R >= 2, C >= 2, and most importantly that left >= 2.
	// since left >= 2, there has to be some zero square.
	// if there is a configuration that works, then there is a configuration that
	// works with a zero in the bottom left, and zeros along the left and bottom
	// edges in a contiguous chunk coming away from the bottom left corner.
	// zero squares correspond to 3x3 boxes within which there are no mines.
	// pretend to move 3x3 boxes around with the center along the edges adjacent
	// to some corner, which yields 2-wide strips.
	// To these we can add any small-enough integer number of squares,
	// by sliding our 3x3 box around so its top-right corner is covering 1 new
	// square.
	// So just look for these configurations, and they exist iff it's possible
	// to make a 1-click game of minesweeper!
	size_t h, w;
	for( h = 1; h <= R-1; ++h )
	for( w = 1; w <= C-1; ++w ) {
		size_t lb = 2*(h+1) + 2*(w+1) - 4;
		size_t ub = (h+1)*(w+1);
		if( left >= lb && left <= ub ) goto found; // fml
	}
	return false;
	found:
	for( size_t i = 0; i < R; ++i )
	for( size_t j = 0; j < C; ++j )
		board[i][j] = '*';
	for( size_t i = 0; i <= h; ++i ) board[i][0] = board[i][1] = '.';
	for( size_t j = 0; j <= w; ++j ) board[0][j] = board[1][j] = '.';
	left -= 2*(h+1) + 2*(w+1) - 4;
	for( size_t i = 1; i < h; ++i )
	for( size_t j = 1; j < w; ++j ) {// for each center
		if( left > 0 ) { board[i+1][j+1] = '.'; --left; } // corner gets added in
		if( left == 0 ) { i = h; j = w; }
	}
	board[0][0] = 'c';
	return true;
}

int main() {
	size_t T; cin >> T;
	for( size_t Case = 1; Case <= T; ++Case ) {
		size_t R, C, M;
		char board[MAXN][MAXN];
		cin >> R >> C >> M;
		cout << "Case #" << Case << ":" << endl;
		if( ok(R,C,M, board) ) {
			for( size_t i = 0; i < R; ++i ) {
				for( size_t j = 0; j < C; ++j )
					cout << board[i][j];
				cout << endl;
			}
		}
		else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
