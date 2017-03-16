#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		int S_max, sum = 0, invite = 0;
		cin >> S_max;
		for (int i = 0; i < S_max + 1; i++) {
			if (sum < i) {
				++sum, ++invite;
			}
			char S_i;
			cin >> S_i;
			sum += S_i-'0';
		}

		cout << "Case #" << test << ": " << invite << endl;
	}
	return 0;
}