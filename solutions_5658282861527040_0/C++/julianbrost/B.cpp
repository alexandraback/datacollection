#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int A, B, K;
		cin >> A >> B >> K;
		long long n = 0;
		for (int a = 0; a < A; ++a) for (int b = 0; b < B; ++b) for (int k = 0; k < K; ++k) {
			if ((a & b) == k) n++;
		}
		cout << "Case #" << t << ": " << n << endl;
	}
}
