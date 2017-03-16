//============================================================================
// Name        : B.cpp
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double testCase() {

	int k, l, s;
	cin >> k >> l >> s;

	int letters[26];
	for (int i = 0; i < 26; i++) {
		letters[i] = 0;
	}

	char c;
	for (int i = 0; i < k; i++) {
		cin >> c;
		letters[c - 'A']++;
	}

	double p = 1;
	char target[l];
	for (int i = 0; i < l; i++) {
		cin >> c;
		target[i] = c;
		p *= (double)letters[c - 'A'] / k;
	}

	int i = 1;
	for (; i < l; i++) {
		int j = 0;
		for (; i + j < l && target[j] == target[i+j]; j++);
		if (i + j == l) {
			break;
		}
	}

	int max = s / l;
	if (k != i) {
		max += (s % l)/(k - i);
	}
	if (max <= 0 || p == 0) {
		return 0.0;
	}
	else {
		return (double)max - max*p;
	}
}

int main() {

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	ifstream in("in.txt");
	cin.rdbuf(in.rdbuf());

	ofstream out("out.txt");
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		double res = testCase();
		cout << "Case #" << i + 1 << ": " << setprecision(7) << fixed << res << '\n';
	}


	in.close();
	out.close();

	return 0;
}
