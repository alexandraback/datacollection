#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;

//vector<string> digits = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

void test()
{
	string s;
	cin >> s;

	vector<int> count(256, 0);
	for (char c : s) {
		count[c] += 1;
	}

	vector<int> A(10, 0);

	// ZERO - Z
	while (count['Z'] > 0) {
		A[0] += 1;
		count['Z']--;
		count['E']--;
		count['R']--;
		count['O']--;
	}

	// TWO - W
	while (count['W'] > 0) {
		A[2] += 1;
		count['T']--;
		count['W']--;
		count['O']--;
	}

	// SIX - X
	while (count['X'] > 0) {
		A[6] += 1;
		count['S']--;
		count['I']--;
		count['X']--;
	}

	// FOUR - U
	while (count['U'] > 0) {
		A[4] += 1;
		count['F']--;
		count['O']--;
		count['U']--;
		count['R']--;
	}

	// EIGHT - G
	while (count['G'] > 0) {
		A[8] += 1;
		count['E']--;
		count['I']--;
		count['G']--;
		count['H']--;
		count['T']--;
	}

	///
	// ONE - O
	while (count['O'] > 0) {
		A[1] += 1;
		count['O']--;
		count['N']--;
		count['E']--;
	}

	// THREE  T H R
	while (count['T'] > 0) {
		A[3] += 1;
		count['T']--;
		count['H']--;
		count['R']--;
		count['E']--;
		count['E']--;
	}

	// FIVE F
	while (count['F'] > 0) {
		A[5] += 1;
		count['F']--;
		count['I']--;
		count['V']--;
		count['E']--;
	}

	// SEVEN S
	while (count['S'] > 0) {
		A[7] += 1;
		count['S']--;
		count['E']--;
		count['V']--;
		count['E']--;
		count['N']--;
	}

	// NINE - any
	while (count['N'] > 0) {
		A[9] += 1;
		count['N']--;
		count['I']--;
		count['N']--;
		count['E']--;
	}

	string res;
	for (int d = 0; d < 10; d++) {
		for (int i = 0; i < A[d]; i++) {
			res += '0' + d;
		}
	}
	cout << res;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		test();
		cout << endl;
	}
	return 0;
}
