
#include <iostream>

using namespace std;


int get(int counts[128], char by, const string &whole) {
	int res = counts[by];
	for (char c : whole) {
		counts[c] -= res;
	}
	return res;
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		int counts[128];
		for (int i = 0; i < 128; i++) counts[i] = 0;

		string s;
		cin >> s;
		for (char c : s) {
			counts[c] ++;
		}
		int digc[10];

		digc[0] = get(counts, 'Z', "ZERO");
		digc[6] = get(counts, 'X', "SIX");
		digc[8] = get(counts, 'G', "EIGHT");
		digc[2] = get(counts, 'W', "TWO");
		digc[7] = get(counts, 'S', "SEVEN");
		digc[5] = get(counts, 'V', "FIVE");
		digc[4] = get(counts, 'F', "FOUR");
		digc[3] = get(counts, 'R', "THREE");
		digc[9] = get(counts, 'I', "NINE");
		digc[1] = get(counts, 'O', "ONE");

		for (int d = 0; d <= 9; d++) {
			for (int c = 0; c < digc[d]; c++) cout << d;
		}
		cout << endl;

	}
	return 0;
}
