#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cout << "Case #" << icase << ": ";
		ll N;
		cin >> N;
		if (N == 0) {
			cout << "INSOMNIA" << endl;
			continue;
		}
		int seen = 0;
		ll m = N;
		while (seen != (1 << 10) - 1) {
			ll n = m;
			while (n > 0) {
				int d = n % 10;
				seen |= (1 << d);
				n /= 10;
			}
			if (seen == (1 << 10) - 1)
				break;
			m += N;
		}
		cout << m << endl;
	}
	return 0;
}
