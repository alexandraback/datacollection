#include <iostream>
#include <sstream>
#include <string>
using namespace std;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		string s;
		cin >> s;
		for (auto& a : s) if (a == '/') a = ' ';
		stringstream ss(s);
		long long P, Q;
		ss >> P >> Q;
		auto cd = gcd(P, Q);
		P /= cd;
		Q /= cd;
		bool possible = true;
		for (long long n = Q; n > 2; n /= 2) {
			if (n % 2 != 0) possible = false;
		}
		if (Q < P) possible = false;
		if (!possible) {
			cout << "Case #" << q << ": impossible" << endl;
			continue;
		}
		while (P > 1) {
			P /= 2;
			Q /= 2;
		}
		int ans = 0;
		while (Q > 1) {
			Q /= 2;
			++ans;
		}
		cout << "Case #" << q << ": " << ans << endl;
	}
	return 0;
}