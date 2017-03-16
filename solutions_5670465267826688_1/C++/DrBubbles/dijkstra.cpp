#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

//// Some gross encoding. i, j, and k are 2, 4, 6, and -x = x ± 1.
//// I don't particularly want to implement matrix multiplication
//// here to do it that way.
//char quat_mult(char X, char Y) {
//	char sign = (X+Y)%2;
//	char ret;
//	int x = X / 2; int y = Y / 2;
//
//	assert ( 0 <= X && X < 8 );
//	assert ( 0 <= Y && Y < 8 );
//
//	if ( x > y ) return quat_mult( Y, X );
//
//	if ( x == 0 || y == 0 ) {
//		ret = x*2 + y*2 + sign;
//	}
//	else if ( x == y ) {
//		ret = 1 - sign;
//	}
//	else if ( x == 1 && y == 3 ) {
//		ret = 5 - sign;
//	}
//	else if ( x == 1 ) {
//		ret = 6 + sign;
//	}
//	else {
//		ret = 2 + sign;
//	}
//
//	assert ( 0 <= ret && ret < 8 );
//	return ret;
//
//}

char quat_mult(char X, char Y) {
	static char table[8][8] =
	{ { 0, 1, 2, 3, 4, 5, 6, 7 },
	  { 1, 0, 3, 2, 5, 4, 7, 6 },
	  { 2, 3, 1, 0, 6, 7, 5, 4 },
	  { 3, 2, 0, 1, 7, 6, 4, 5 },
	  { 4, 5, 7, 6, 1, 0, 2, 3 },
	  { 5, 4, 6, 7, 0, 1, 3, 2 },
	  { 6, 7, 4, 5, 3, 2, 1, 0 },
	  { 7, 6, 5, 4, 2, 3, 0, 1 } };

	assert ( 0 <= X && X < 8 );
	assert ( 0 <= Y && Y < 8 );

	return table[X][Y];
}

void test_quat_mult() {
	for ( int i = 0; i < 8; ++i ) {
		assert( quat_mult(0, i) == i );
		assert( quat_mult(i, 0) == i );

		assert( quat_mult(1, i) == ((i%2)?i-1:i+1) );
		assert( quat_mult(i, 1) == ((i%2)?i-1:i+1) );
	}

	for ( int i = 1; i < 4; ++i ) {
		cout << i << endl;
		assert( quat_mult(2*i, 2*i) == 1 );
		assert( quat_mult(2*i, 2*i+1) == 0);
		assert( quat_mult(2*i+1, 2*i+1) == 1 );
		assert( quat_mult(2*i+1, 2*i) == 0);
	}

	assert( quat_mult( 2, 4 ) == 6 );
	assert( quat_mult( 2, 5 ) == 7 );
	assert( quat_mult( 2, 6 ) == 5 );
	assert( quat_mult( 2, 7 ) == 4 );

}

bool solveacase() {

	int L;
	long long X_in;
	cin >> L >> X_in;

	// Every element of the quaternion group has order at most four.
	// Thus four consecutive copies of L are equivalent to not having it.
	// We are therefore justified in considering smaller X.
	
	int X = (int)(X_in > 12 ? 12 + (X_in % 4) : X_in);

	string ijk; cin >> ijk;
	//char* cuts = new char[L+1];
	//cuts[0] = 0;
	//
	//for ( int i = 0; i < L; ++i ) {
	//	char quat = (ijk[i+1] - 'i' + 1) * 2;
	//	cuts[i+1] = quat_mult( cuts[i], quat );
	//}

//	// Since ijk = -1, if the entire product is not -1, we can immediately
//	// reject as there is no way it will be able to factor into this form.
//	char big = 0;
//	for ( int i = 0; i < X%4; ++i ) {
//		big = quat_mult( big, cuts[L] );
//	}
//	if ( big != 1 ) return false;
//
//	big = 0;
//	for ( int BLOCK = 0; BLOCK < 4 && BLOCK < X_in; ++BLOCK ) {
//		for ( int i = 0; i < L; ++i ) {
//			if ( quat_mult( big, cuts[L] ) == 2 ) {
//				// Check the rest of this block...
//				for ( in
//			}
//		}
//
//		big = quat_mult( big, cuts[L] );
//	}
//

	char cur = 0;
	char block_val = 0;
	bool found_i = false;
	bool found_j = false;
	for ( int BLOCK = 0; BLOCK < 8 && BLOCK < X; ++BLOCK ) {
		for ( int i = 0; i < L; ++i ) {
			char quat = (ijk[i] - 'i' + 1) * 2;
			cur = quat_mult(cur, quat);

			if ( !found_i && cur == 2 ) {
				found_i = true;
			}
			else if ( found_i && !found_j && cur == 6 ) {
				found_j = true;
			}
		}

		if ( BLOCK == 0 ) {
			block_val = cur;
			char total = 0;
			for ( int Z = 0; Z < X%4; ++Z ) {
				total = quat_mult( total, block_val );
			}

			if ( total != 1 ) return false;
		}
		else if ( found_j ) break;
	}

	return found_j;

}

int main ( int, char** ) {

	int T;
	cin >> T;

	//test_quat_mult();

	for ( int i = 1; i <= T; ++i ) {
		cerr << i << endl;
		bool r = solveacase();

		cout << "Case #" << i << ": " << (r?"YES":"NO") << endl;
	}


	return 0;
}
