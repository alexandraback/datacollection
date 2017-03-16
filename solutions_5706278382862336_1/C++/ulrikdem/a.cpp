#include <iostream>
#include <utility>
using namespace std;

long long gcd(long long a, long long b) {
	while(b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		
		long long numerator, denominator;
		char ignore;
		cin >> numerator >> ignore >> denominator;
		long long factor = gcd(numerator, denominator);
		numerator /= factor;
		denominator /= factor;

		if(0x10000000000ll % denominator) {
			cout << "Case #" << test << ": impossible\n";
			continue;
		}
		numerator *= 0x10000000000ll / denominator;
		denominator = 0x10000000000ll;

		int answer = 40;
		while(numerator >>= 1) {
			--answer;
		}
		cout << "Case #" << test << ": " << answer << '\n';
	}
	return 0;
}
