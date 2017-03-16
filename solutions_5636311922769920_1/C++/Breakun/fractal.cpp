#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ":";

		int K, C, S;
		cin >> K >> C >> S;

		if (S * C < K) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			for (int i = 0; i < K; i += C) {
				long long value = 0LL;
				for (int j = 0; j < C; j++) {
					value *= K;
					value += (i + j) % K;
				}
				cout << " " << value + 1;
			}
			cout << endl;
		}
	}
	return 0;
}
