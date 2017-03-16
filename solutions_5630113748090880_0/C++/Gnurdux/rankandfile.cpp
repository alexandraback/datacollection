#include <iostream>
#include <vector>
using namespace std;

bool oddappears[10000];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		for (int i = 0; i < 10000; i++) oddappears[i] = false;

		for (int i = 0; i < 2*N-1; i++) {
			for (int j = 0; j < N; j++) {
				int val;
				cin >> val;
				oddappears[val] ^= 1;
			}
		}

		cout << "Case #" << t << ':';
		for (int i = 0; i < 10000; i++) {
			if (oddappears[i]) cout << ' ' << i;
		}
		cout << '\n';
	}

	return 0;
}
