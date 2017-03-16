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

int s[506];
int re[506];

int rec( int index, int delta, int chosen ) {
	if( index == 0 ) {
		// omit
		if( delta == 0 && chosen != 0 ) {
			re[index] = 0;
			return 1;
		}
		if( s[0] == delta ) {
			re[index] = -1;
			return 1;
		}
		return 0;
	}
	// omit
	if( rec( index-1, delta, chosen ) ) {
		re[index] = 0;
		return 1;
	}
	// add
	if( rec( index-1, delta+s[index], 1 ) ) {
		re[index] = 1;
		return 1;
	}
	// diff
	if( rec( index-1, abs(delta-s[index]), 1 ) ) {
		re[index] = -1;
		return 1;
	}

	return 0;
}

int main() {
	int cases;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n;
		cin >> n;
		for( int i = 0; i < n; ++i ) {
			cin >> s[i];
		}
		cout << "Case #" << caseid << ":\n";
		if( !rec( n-1, 0, 0 ) ) {
			cout << "Impossible\n";
		} else {
			vector<int> v[2];
			int v_sum[2] = {0,0};
			int delta = 0;
			for( int i = n-1; i >= 0; --i ) {
				if( re[i] == 0 ) continue;
				if( re[i] == 1 ) {
					v[delta].push_back( s[i] );
					v_sum[delta] += s[i];
				} else {
					v[1-delta].push_back( s[i] );
					v_sum[1-delta] += s[i];

					if( v_sum[0] > v_sum[1] ) {
						delta = 0;
					} else {
						delta = 1;
					}
				}
			}
			int sum[2] = {0,0};
			int first = 1;
			for( int i = 0; i < (int)v[0].size(); ++i ) {
				if( first ) first = 0; else cout << ' ';
				cout << v[0][i];
				sum[0] += v[0][i];
			}
			cout << endl;
			first = 1;
			for( int i = 0; i < (int)v[1].size(); ++i ) {
				if( first ) first = 0; else cout << ' ';
				cout << v[1][i];
				sum[1] += v[1][i];
			}
			cout << endl;
			assert( sum[0] == sum[1] );
		}
	}
	return 0;
}

