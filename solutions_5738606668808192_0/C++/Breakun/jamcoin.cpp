#include <iostream>
#include <vector>
using namespace std;

int divisor(long long n) {
	for (int i = 2; i <= 100; i++)
		if (n % i == 0LL)
			return i;

	return 0;
}

int main() {
	int T, N, J;
	cin >> T >> N >> J;
	cout << "Case #1:" << endl;

	for (int i = 0; i < (1 << (N - 2)); i++) {
		int v = (i << 1) | (1 << (N - 1)) | 1;
		int divisors[9];

		bool chk = true;
		long long value;
		for (int b = 2; b <= 10; b++) {
			int tmp = v;
			long long power = 1LL;
			value = 0LL; 
			while (tmp) {
				if (tmp % 2)
					value += power;
				tmp /= 2;
				power *= b;
			}
			
			divisors[b - 2] = divisor(value);
			if (divisors[b - 2] == 0) {
				chk = false;
				break;
			}
		}

		if (chk) {
			cout << value;
			for (int i = 0; i < 9; i++)
				cout << " " << divisors[i];
			cout << endl;

			J--;
			if (J == 0)
				return 0;
		}
	}

	return 1;
}
