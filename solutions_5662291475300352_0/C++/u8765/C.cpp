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

typedef pair<int,int> PI;

struct group {
	int start, number, time;
};

struct hiker {
	int start, time;
};

int main() {
	int cases;
	group g[1000];
	vector<hiker> h;

	cin >> cases;

	for( int caseno = 1; caseno <= cases; ++caseno ) {
		cout << "Case #" << caseno << ": ";
		int N;
		cin >> N;
		int total = 0;
		for( int i = 0; i < N; ++i ) {
			cin >> g[i].start >> g[i].number >> g[i].time;
			assert( g[i].start != 0 );
			total += g[i].number;
		}
		assert( total <= 2 );
		h.clear();
		for( int i = 0; i < N; ++i ) {
			for( int j = 0; j < g[i].number; ++j ) {
				h.push_back( { g[i].start, g[i].time+j } );
			}
		}
		if( h[0].time == h[1].time ) {
			assert( h[0].start != h[1].start );
			cout << 0 << endl;
			continue;
		}
		if( h[0].start > h[1].start ) swap( h[0], h[1] );

		int res = -1;
		if( h[1].time < h[0].time ) {
			if( (360-h[0].start)*h[0].time >= h[1].time * (720-h[1].start) ) {
				res = 1;
			} else {
				res = 0;
			}
		} else {
			if( (360-h[0].start)*h[0].time >= h[1].time * (360-h[1].start) ) {
				res = 0;
			} else {
				res = 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}

