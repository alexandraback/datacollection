/////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <string>
#include <sstream>
#include <iostream>
#include <deque>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

const char* GABRIEL = "GABRIEL";
const char* RICHARD = "RICHARD";

void normalize( vector<string>& v ) {
	int n = v.size();
	assert( n >= 1 );
	assert( (int)v[0].size() == n );

	// move left
	for( int c = 0; c < n; ++c ) {
		bool colEmpty = true;
		for( int r = 0; r < n; ++r ) {
			if( v[r][c] == '*' ) {
				colEmpty = false;
				break;
			}
		}
		if( !colEmpty ) {
			if( c == 0 ) break;
			vector<string> w;
			string rest(c,' ');
			for( int r = 0; r < n; ++r ) {
				w.push_back( v[r].substr( c ) + rest );
			}
			v = w;
			break;
		}
	}

	// move up
	for( int r = 0; r < n; ++r ) {
		bool rowEmpty = true;
		for( int c = 0; c < n; ++c ) {
			if( v[r][c] == '*' ) {
				rowEmpty = false;
				break;
			}
		}
		if( !rowEmpty ) {
			if( r == 0 ) break;
			vector<string> w;
			for( int i = r; i < n; ++r ) {
				w.push_back(v[i]);
			}
			string rest(n,' ');
			for( int i = 0; i < r; ++i ) {
				w.push_back(rest);
			}
			v = w;
			break;
		}
	}
}

vector<string> reflect( const vector<string>& v ) {
	int n = v.size();
	assert( n >= 1 );
	assert( (int)v[0].size() == n );

	vector<string> w;
	string empty(n,' ');
	for( int i = 0; i < n; ++i ) {
		w.push_back(empty);
	}

	for( int r = 0; r < n; ++r ) {
		for( int c = 0; c < n; ++c ) {
			w[r][c] = v[r][n-1-c];
		}
	}

	normalize(w);
	return w;
}

vector<string> rotate90( const vector<string>& v ) {
	int n = v.size();
	assert( n >= 1 );
	assert( (int)v[0].size() == n );

	vector<string> w;
	string empty(n,' ');
	for( int i = 0; i < n; ++i ) {
		w.push_back(empty);
	}

	for( int r = 0; r < n; ++r ) {
		for( int c = 0; c < n; ++c ) {
			w[c][n-1-r] = v[r][c];
		}
	}

	normalize(w);
	return w;
}

typedef pair<vector<string>,int> P;

set<P> generate( const vector<vector<string>>& v ) {
	set<P> res;

	for( int i = 0; i < (int)v.size(); ++i ) {
		auto x = v[i];

		res.insert( P(x,i) );
		x = rotate90(x);
		res.insert( P(x,i) );
		x = rotate90(x);
		res.insert( P(x,i) );
		x = rotate90(x);
		res.insert( P(x,i) );

		x = v[i];
		x = reflect(x);

		res.insert( P(x,i) );
		x = rotate90(x);
		res.insert( P(x,i) );
		x = rotate90(x);
		res.insert( P(x,i) );
		x = rotate90(x);
		res.insert( P(x,i) );
	}
	return res;
}

set<P> gen2() {
	vector<vector<string>> basic;

	vector<string> x = {
			"**",
			"  "
	};

	return generate( { x } );
}

set<P> gen3() {
	vector<string> x = {
		"***",
		"   ",
		"   "
	};

	vector<string> y = {
		"** ",
		"*  ",
		"   "
	};

	return generate( { x, y } );
}

set<P> gen4() {
	vector<string> a = {
		"**  ",
		"**  ",
		"    ",
		"    "
	};

	vector<string> b = {
		"**  ",
		"*   ",
		"*   ",
		"    "
	};

	vector<string> c = {
		"*   ",
		"**  ",
		"*   ",
		"    "
	};

	vector<string> d = {
		"*   ",
		"**  ",
		" *  ",
		"    "
	};

	vector<string> e = {
		"*   ",
		"*   ",
		"*   ",
		"*   "
	};

	return generate( { a, b, c, d, e } );
}

void output( const vector<string>& x ) {
	for( int i = 0; i < (int)x.size(); ++i ) {
		cout << x[i] << endl;
	}
	cout << endl;
}

int rows, cols;
int result_block_mask;

bool fits( char b[4][4], int r, int c, const vector<string>& blk ) {
	int n = blk.size();

	for( int i = 0; i < n; ++i ) {
		for( int j = 0; j < n; ++j ) {
			if( blk[i][j] == '*' ) {
				// b[r+i][c+j] must be free
				if( r+i >= rows || c+j >= cols || b[r+i][c+j] == '*' ) return false;
			}
		}
	}
	return true;
}

int apply_to_mask( int mask, int r, int c, const vector<string>& blk ) {
	int n = blk.size();

	for( int i = 0; i < n; ++i ) {
		for( int j = 0; j < n; ++j ) {
			if( blk[i][j] == '*' ) {
				mask |= 1<<((r+i)*cols+(c+j));
			}
		}
	}
	return mask;
}

char dp[1<<16][1<<5];

void rec( int mask, int block_mask, set<P> blocks ) {
	if( dp[mask][block_mask] ) return;
	dp[mask][block_mask] = 1;

	if( mask == (1<<(rows*cols))-1 ) {
		result_block_mask |= block_mask;
		return;
	}

	char b[4][4];
	for( int r = 0; r < rows; ++r ) {
		for( int c = 0; c < cols; ++c ) {
			b[r][c] = (mask & (1<<(r*cols+c))) ? '*' : ' ';
		}
	}
	for( int r = 0; r < rows; ++r ) {
		for( int c = 0; c < cols; ++c ) {
			if( b[r][c] == ' ' ) {
				for( auto& blk : blocks ) {
					if( fits( b, r, c, blk.first ) ) {
						rec( apply_to_mask( mask, r, c, blk.first ), block_mask | (1<<blk.second), blocks );
					}
				}
			}
		}
	}
}

int main() {
	auto block2 = gen2();
//	for( auto& x : block2 ) {
//		output( x );
//	}

	auto block3 = gen3();
//	for( auto& x : block3 ) {
//		output( x );
//	}

	auto block4 = gen4();
//	for( auto& x : block4 ) {
//		output( x );
//	}

	int cases;

	cin >> cases;

	for( int caseno = 1; caseno <= cases; ++caseno ) {
		cout << "Case #" << caseno << ": ";
		int X;
		cin >> X >> rows >> cols;
		assert( 1 <= X && X <= 4 );
		if( X == 1 ) {
			cout << GABRIEL << endl;
			continue;
		}
		set<P> blocks;
		int basic_blocks;
		if( X == 2 ) {
			blocks = block2;
			basic_blocks = 1;
		} else if( X == 3 ) {
			blocks = block3;
			basic_blocks = 2;
		} else {
			blocks = block4;
			basic_blocks = 5;
		}

		memset( dp, 0, sizeof(dp) );
		result_block_mask = 0;

		rec( 0, 0, blocks );

		if( result_block_mask == (1<<basic_blocks)-1 ) {
			cout << GABRIEL << endl;
		} else {
			cout << RICHARD << endl;
		}
	}
	return 0;
}

