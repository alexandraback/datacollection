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

typedef long long LL;

LL A, B, K;

LL memo[32][2][2][2];

LL rec( int k, int abel, int bbel, int kbel ) {
	if( k < 0 ) return 1;

	LL& res = memo[k][abel][bbel][kbel];
	if( res != -1 ) return res;

	res = 0;

	int Ax = ((A-1)&(1LL<<k)) != 0;
	int Bx = ((B-1)&(1LL<<k)) != 0;
	int Kx = ((K-1)&(1LL<<k)) != 0;

	// 1,0
	if( abel || Ax ) {
		res += rec( k-1, abel, bbel || Bx, kbel || Kx );
	}

	// 0,1
	if( bbel || Bx ) {
		res += rec( k-1, abel || Ax, bbel, kbel || Kx );
	}

	// 0,0
	res += rec( k-1, abel || Ax, bbel || Bx, kbel || Kx );

	// place 1
	if( (kbel || Kx) && (abel || Ax) && (bbel || Bx) ) {
		res += rec( k-1, abel, bbel, kbel );
	}

	return res;
}

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		cin >> A >> B >> K;
		memset( memo, -1, sizeof(memo) );
		cout << rec( 30, 0, 0, 0 ) << endl;
	}
	return 0;
}

