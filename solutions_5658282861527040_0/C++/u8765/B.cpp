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

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		int A, B, K;
		cin >> A >> B >> K;
		int cnt = 0;
		for( int a = 0; a < A; ++a ) {
			for( int b = 0; b < B; ++b ) {
				if( (a&b) < K ) ++cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

