#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

string flip(string s, int i) {
	string s2 = s;
	for ( int j = 0; j <i; ++j ) {
		s2[j] = s[i - j - 1];
		if ( s2[j] == '+' ) {s2[j] = '-';}
		else { s2[j] = '+'; }
	}
	return s2;
}

int solveacase() {
	string s;
	cin >> s;

	int flips = 0;
	int neg = s.find('-');
	while ( neg != string::npos ) {
		cerr << s << endl;
		if ( neg == 0 ) {
			int j = s.rfind('-');
			s = flip(s, j+1);
		}
		else {
			s = flip(s, neg);
		}
		flips++;
		neg = s.find('-');
	}

	return flips;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		int r = solveacase();

		cout << "Case #" << i << ": " << r << endl;
	}


	return 0;
}
