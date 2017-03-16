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
#include <queue>
#include <cstring>

using namespace std;

int x[1000];

int main() {
	int cases;

	cin >> cases;

	for (int caseno = 1; caseno <= cases; ++caseno) {
		cout << "Case #" << caseno << ": ";
		int D;
		cin >> D;
		assert(1 <= D && D <= 1000);
		int maxx = -1;
		for( int i = 0; i < D; ++i ) {
			cin >> x[i];
			maxx = max( maxx, x[i] );
		}
		int res = 1000000000;
		for( int i = 1; i <= maxx; ++i ) {
			int tmp = i;
			for( int j = 0; j < D; ++j ) {
				tmp += (x[j]+i-1)/i-1;
			}
			res = min( res, tmp );
		}
		cout << res << endl;
	}
	return 0;
}

