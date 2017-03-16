#include <iostream>
using namespace std;

bool is_palindrome(long long x) {
	static char digits[15];
	int d = 0;
	while (x != 0) {
		digits[d] = x % 10;
		x /= 10;
		++d;
	}

	for (int i = 0; i <= d / 2 - 1; ++i) {
		if (digits[i] != digits[d - i - 1]) {
			return false;
		}
	}
	return true;
}

long long rec(int d, int digits, char* number, long long x, long long a, long long b, long long& count) {
	if (d <= (digits - 1) / 2) {
		for (char i = (d == 0 ? 1 : 0); i < 9; ++i) {
			number[d] = i;
			rec(d + 1, digits, number, x*10 + i, a, b, count);
		}
	} else {
		for (int d2 = digits / 2 - 1; d2 >= 0; --d2) {
			x = x*10 + number[d2];
		}

		long long x2 = x*x;
		if (a <= x2 && x2 <= b && is_palindrome(x2)) {
			++count;
		}
	}
}

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		long long a, b;
		cin >> a >> b;

		long long count = 0;
		long long pow10 = 1;
		for (int digits = 1; digits <= 7; ++digits, pow10 *= 10) {
			if (pow10*pow10 > b) {
				break;
			}
			if ((pow10*10 - 1)*(pow10*10 - 1) < a) {
				continue;
			}

			char number[7];
			rec(0, digits, number, 0, a, b, count);
		}

		cout << "Case #" << test << ": " << count << endl;
	}
}
