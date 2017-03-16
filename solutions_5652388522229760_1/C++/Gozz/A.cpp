#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		i64 N;
		cin >> N;
		if (N == 0) {
			cout << "Case #" << (t+1) << ": " << "INSOMNIA" << endl;
			continue;
		}
		i64 D = N;
		i64 P = 0;
		while (D > 0) {
			D /= 10;
			++P;
		}
		D = 10;
		while (P-- > 0) D *= 10;
		P = D;
		D = 0;
		bitset<10> digits;
		while (!digits.all() && D < P * N) {
			D += N;
			int tmp = D;
			while (tmp > 0) {
				digits.set(tmp % 10);
				tmp /= 10;
			}
		}
		if (digits.all()) {
			cout << "Case #" << (t+1) << ": " << D << endl;
		} else {
			cout << "Case #" << (t+1) << ": " << "INSOMNIA" << endl;
		}
	}
	return 0;
}