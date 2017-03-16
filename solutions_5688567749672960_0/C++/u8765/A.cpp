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

const int NN =50000004;
int val[NN];
deque<int> d;

int main() {
	int cases;

	cin >> cases;

	for( int caseno = 1; caseno <= cases; ++caseno ) {
		cout << "Case #" << caseno << ": ";
		int N;
		cin >> N;

		if( N == 1 ) {
			cout << 1 << endl;
			continue;
		}

		memset( val, 0, sizeof(val) );
		val[1] = 1;
		d.clear();
		d.push_back(1);

		while( !d.empty() ) {
			int k = d.front(); d.pop_front();
			assert( k != 0 );
			if( k == N ) break;

			if( val[k+1] == 0 ) {
				val[k+1] = val[k] + 1;
				d.push_back(k+1);
			}
			int y = 0;
			for( int x = k; x; x /= 10 ) {
				y = 10*y + (x%10);
			}
			if( y < NN && val[y] == 0 ) {
				val[y] = val[k]+1;
				d.push_back(y);
			}
		}
		assert( val[N] != 0 );
		cout << val[N] << endl;
	}
	return 0;
}

