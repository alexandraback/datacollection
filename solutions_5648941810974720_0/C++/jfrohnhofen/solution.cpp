#include <iostream>

using namespace std;

void solve_testcase() {
	uint32_t counts[256] = {0};

	string S;
	cin >> S;

	for (auto &ch : S) {
		counts[ch]++;
	}

	uint32_t digits[10] = {0};
	digits[0] = counts['Z'];
	digits[6] = counts['X'];
	digits[8] = counts['G'];
	digits[4] = counts['U'];
	digits[2] = counts['W'];
	digits[3] = counts['R'] - digits[0] - digits[4];
	digits[5] = counts['F'] - digits[4];
	digits[7] = counts['V'] - digits[5];
	digits[9] = counts['I'] - digits[5] - digits[6] - digits[8];
	digits[1] = counts['N'] - 2 * digits[9] - digits[7];

	for (auto i=0; i<10; ++i) {
		for (auto j=0; j<digits[i]; ++j) {
			cout << (char)('0' + i);
		}
	}
}

int main() {
	uint32_t T;
	cin >> T;
	
	for (auto t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		solve_testcase();
		cout << endl;
	}
}
