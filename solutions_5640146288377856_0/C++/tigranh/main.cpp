/*
 * main.cpp
 *
 *  Created on: 10 ???, 2015 ?.
 *      Author: Tigran
 */



#include <iostream>

using namespace std;

int solve( int R, int C, int W )
{
	int r = 0;
	int last_i, last_j;
	for ( int i = 0; i < R; ++i ) {
		for ( int j = W - 1; j < C; j += W ) {
			last_i = i;
			last_j = j;
			++r;
		}
	}
	int hit = 1;
	if ( C % W == 0 )
		return r + W - 1;
	else
		return r + W;
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		int R, C, W;
		cin >> R >> C >> W;
		cout << "Case #" << tc << ": " << solve( R, C, W ) << endl;
	}
	return 0;
}
