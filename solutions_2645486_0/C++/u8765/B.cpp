#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cmath>
#include <deque>
#include <cassert>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int E, R, N;
int v[10];
int memo[11][6];

int rec( int index, int e ) {
	if( index == N ) {
		return 0;
	}
	int& res = memo[index][e];
	if( res != -1 ) return res;
	res = 0;
	
	for( int i = 0; i <= e; ++i ) {
		// spend i
		res = max( res, i*v[index] + rec( index+1, min( e-i+R, E ) ) );
	}
	
	return res;
}

int main() {
	int cases;
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cin >> E >> R >> N;
		assert( 1 <= N && N <= 10 );
		for( int i = 0; i < N; ++i ) {
			cin >> v[i];
		}
		memset( memo, -1, sizeof(memo) );
		cout << "Case #" << caseid << ": " << rec( 0, E ) << endl;
	}
	return 0;
}

