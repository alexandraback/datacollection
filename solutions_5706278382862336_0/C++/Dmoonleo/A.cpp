#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		char sep;
		long long a, b;
		cin >> a >> sep >> b;
		long long g = gcd(a, b);
		a /= g;
		b /= g;
		int times;
		bool flag = true;
		long long tempb = b;
		while (b>1) {
			if (b % 2 == 1) {
				flag = false;
			}
			b /= 2;
		}
		b = tempb;
		long long standard = 1LL << 40;
		cout << "Case #" << c << ": ";
		if (flag == false) {
			cout << "impossible" << endl;
		} else {
			while (b < standard) {
				a <<= 1;
				b <<= 1;
			}
			int num = 0;
			while (a > 1) {
				a >>= 1;
				num++;
			}
			cout << 40-num << endl;
		}
	}
	return 0;
}