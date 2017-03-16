#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

void solveacase() {
	string s;
	cin >> s;
	int histo[256];
	int nums[10];

	for ( int i = 0; i < 256; ++i ) {
		histo[i] = 0;
	}

	for ( int i = 0; i < 10; ++i ) {
		nums[i] = 0;
	}

	for ( int i = 0; i < s.length(); ++i ) {
		histo[s[i]]++;
	}

	while(histo['Z'] > 0) {
		nums[0]++;
		histo['Z']--;
		histo['E']--;
		histo['R']--;
		histo['O']--;
	}
	while(histo['X'] > 0) {
		nums[6]++;
		histo['S']--;
		histo['I']--;
		histo['X']--;
	}
	while(histo['G'] > 0) {
		nums[8]++;
		histo['E']--;
		histo['I']--;
		histo['G']--;
		histo['H']--;
		histo['T']--;
	}
	while(histo['U'] > 0) {
		nums[4]++;
		histo['F']--;
		histo['O']--;
		histo['U']--;
		histo['R']--;
	}
	while(histo['R'] > 0) {
		nums[3]++;
		histo['T']--;
		histo['R']--;
		histo['H']--;
		histo['E']-=2;
	}
	while(histo['W'] > 0) {
		nums[2]++;
		histo['T']--;
		histo['O']--;
		histo['W']--;
	}
	while(histo['O'] > 0) {
		nums[1]++;
		histo['N']--;
		histo['O']--;
		histo['E']--;
	}

	while(histo['F'] > 0) {
		nums[5]++;
		histo['F']--;
		histo['I']--;
		histo['V']--;
		histo['E']--;
	}

	while(histo['V'] > 0) {
		nums[7]++;
		histo['S']--;
		histo['E']--;
		histo['V']--;
		histo['E']--;
		histo['N']--;
	}

	nums[9] = histo['I'];

	for ( int i = 0; i < 10; ++i ) {
		for( int j = 0; j < nums[i]; ++j ) {
			cout << i;
		}
	}
	cout << endl;
	return ;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		cout << "Case #" << i << ": ";
		solveacase();
	}


	return 0;
}
