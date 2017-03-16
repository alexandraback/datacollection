#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void compute() {
	string str;
	cin >> str;
	vector<int> c(26, 0);
	for(int i = 0; i < str.length(); ++i) {
		++c[str[i] - 'A'];
	}
	vector<int> r(10, 0);
	// 0
	while(c['Z' - 'A'] > 0) {
		++r[0];
		--c['Z' - 'A'];
		--c['E' - 'A'];
		--c['R' - 'A'];
		--c['O' - 'A'];
	}
	// 2
	while(c['W' - 'A'] > 0) {
		++r[2];
		--c['T' - 'A'];
		--c['W' - 'A'];
		--c['O' - 'A'];
	}
	// 6
	while(c['X' - 'A'] > 0) {
		++r[6];
		--c['S' - 'A'];
		--c['I' - 'A'];
		--c['X' - 'A'];
	}
	// 8
	while(c['G' - 'A'] > 0) {
		++r[8];
		--c['E' - 'A'];
		--c['I' - 'A'];
		--c['G' - 'A'];
		--c['H' - 'A'];
		--c['T' - 'A'];
	}
	// 3
	while(c['T' - 'A'] > 0) {
		++r[3];
		--c['T' - 'A'];
		--c['H' - 'A'];
		--c['R' - 'A'];
		--c['E' - 'A'];
		--c['E' - 'A'];
	}
	// 4
	while(c['U' - 'A'] > 0) {
		++r[4];
		--c['F' - 'A'];
		--c['O' - 'A'];
		--c['U' - 'A'];
		--c['R' - 'A'];
	}
	// 5
	while(c['F' - 'A'] > 0) {
		++r[5];
		--c['F' - 'A'];
		--c['I' - 'A'];
		--c['V' - 'A'];
		--c['E' - 'A'];
	}
		// 7
	while(c['S' - 'A'] > 0) {
		++r[7];
		--c['S' - 'A'];
		--c['E' - 'A'];
		--c['V' - 'A'];
		--c['E' - 'A'];
		--c['N' - 'A'];
	}
	// 1
	while(c['O' - 'A'] > 0) {
		++r[1];
		--c['O' - 'A'];
		--c['N' - 'A'];
		--c['E' - 'A'];
	}
	r[9] = c['I'-'A'];
	for(int i = 0; i < 10; ++i) {
		for (int j = 0 ; j < r[i]; ++j) {
			cout << i;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": "; 
		compute();
		cout << endl;
	}
	return 0;
}
