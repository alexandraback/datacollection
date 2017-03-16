#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main() {
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	for (ll z = 1; z <= t; z++) {
		bool dig[10];
		memset(dig, false, sizeof(dig));
		cin >> n;
		if (!n) {
			cout << "Case #" << 1 <<": INSOMNIA" << endl;
			continue;
		}
		ll qnt = 0;
		ll partial = n;
		while (qnt < 10) {
			ll x = partial;
			while (x) {
				if (!dig[x % 10]) {
					dig[x % 10] = true;
					qnt++;
				}
				x /= 10;
			}
			partial += n;
		}
		partial -= n;
		cout << "Case #" << z << ": " << partial << endl;
	}
		
	return 0;
}
