#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

char x[54][54];

void print_board( int R, int C, bool swapped ) {
	if( !swapped ) {
		for( int r = 0; r < R; ++r ) {
			x[r][C] = '\0';
			cout << x[r] << endl;
		}
	} else {
		for( int c = 0; c < C; ++c ) {
			for( int r = 0; r < R; ++r ) cout << x[r][c];
			cout << endl;
		}
	}
}

const char* IMPOSSIBLE = "Impossible";

bool b3( int R, int C, int M ) {
	for( int r = 0; r < R; ++r ) {
		for( int c = 0; c < C; ++c ) {
			x[r][c] = '*';
		}
	}
	x[R-1][C-1] = 'c';
	x[R-1][C-2] = x[R-2][C-1] = x[R-2][C-2] = '.';
	int c2 = C-2;
	int r2 = R-2;
	int free = 4;
	bool last_r = true;

	while( free < R*C-M ) {
		int diff = R*C-M-free;
		bool r_poss = diff >= 2 && r2 > 0;
		bool c_poss = diff >= 2 && c2 > 0;

		if( r_poss && c_poss ) {
			if( last_r ) r_poss = false;
			else c_poss = false;
		}

		if( r_poss ) {
			free += 2;
			--r2;
			x[r2][C-1] = x[r2][C-2] = '.';
			last_r = true;
			continue;
		}
		if( c_poss ) {
			free += 2;
			--c2;
			x[R-1][c2] = x[R-2][c2] = '.';
			last_r = false;
			continue;
		}

		if( r2 == R-2 || c2 == C-2 ) break;

		for( int r = R-3; r >= r2 && R*C-M-free > 0; --r ) {
			for( int c = C-3; c >= c2 && R*C-M-free > 0; --c ) {
				x[r][c] = '.';
				++free;
			}
		}
		break;
	}

	return free == R*C-M;
}

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ":\n";

		int R, C, M;
		cin >> R >> C >> M;

		if( M == 0 ) {
			for( int r = 0; r < R; ++r ) {
				for( int c = 0; c < C; ++c ) {
					x[r][c] = '.';
				}
			}
			x[0][0] = 'c';
			print_board(R,C,false);
			continue;
		}

		if( M == R*C-1 ) {
			for( int r = 0; r < R; ++r ) {
				for( int c = 0; c < C; ++c ) {
					x[r][c] = '*';
				}
			}
			x[0][0] = 'c';
			print_board(R,C,false);
			continue;
		}

		int R_orig = R;
		int C_orig = C;

		bool swapped = false;
		if( R > C ) {
			swap( R, C );
			swapped = true;
		}
		// R <= C

		if( R == 1 ) {
			for( int c = 0; c < C-1; ++c ) {
				if( c < M ) x[0][c] = '*';
				else x[0][c] = '.';
			}
			x[0][C-1] = 'c';
			print_board(R,C,swapped);
			continue;
		}

		if( M == R*C-2 || M == R*C-3 ) {
			cout << IMPOSSIBLE << endl;
			continue;
		}

		if( R == 2 ) {
			if( (M%4)==1 || (M%4)==3 ) {
				cout << IMPOSSIBLE << endl;
				continue;
			}
			int m = 0;
			for( int c = 0; c < C; ++c ) {
				for( int r =0 ; r < 2; ++r ) {
					if( m < M ) {
						x[r][c] = '*';
						++m;
					} else {
						x[r][c] = '.';
					}
				}
			}
			x[0][C-1] = 'c';
			print_board(R,C,swapped);
			continue;
		}
		// 3 <= R_orig,C_orig
		assert( 3 <= R_orig && 3 <= C_orig );
		if( b3( R_orig, C_orig, M ) ) {
			print_board( R_orig, C_orig, false );
			continue;
		}
		if( b3( C_orig, R_orig, M ) ) {
			print_board( C_orig, R_orig, true );
			continue;
		}
		cout << IMPOSSIBLE << endl;
	}
	return 0;
}
