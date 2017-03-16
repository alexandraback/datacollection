#include <iostream>

using namespace std;

long long p, q;
int t;
char c;

long long gcd(long long a, long long b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> p >> c >> q;
		cout << "Case #" << i + 1 << ": ";
		long long g = gcd(p, q);
		p /= g;
		q /= g;
		long long q0 = q;
		while (q0 > 1 && (q0 % 2 == 0)) {
			q0 = q0 >> 1;
		}
		if (q0 != 1) {
			cout << "impossible" << endl;
		} else {
			int ans = 0;
			while (q > p) {
				ans++;
				q /= 2;
			}
			cout << ans << endl;
		}
	}
}