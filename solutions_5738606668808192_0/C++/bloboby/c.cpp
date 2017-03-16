#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

ll div(ll m) {
	if (m%2 == 0) return 2;
	int k = 3;
	while (k <= 20) {
		if (m%k == 0) return k;
		k += 2;
	}
	return 0;
}

int main() {
	ll T, N, J;
	cin >> T >> N >> J;
	cout << "Case #1:" << endl;
	
	ll jam[20];
	jam[0] = 1;
	jam[N-1] = 1;
	ll p = pow(2,N-2);
	for (ll i=0; i<p; i++) {
		if (J == 0) break;
		
		// put digits into array
		ll k = i;
		for (ll j=0; j<N-2; j++) {
			jam[1+j] = k % 2;
			k /= 2;
		}
		
		// check all bases
		bool coin = true;
		vector<ll> divs;
		for (ll b=2; b<=10; b++) {
			ll m = 0;
			for (ll j=0; j<N; j++) {
				m += jam[j] * pow(b,j);
			}
			if (div(m) == 0) {
				coin = false;
				break;
			} else {
				divs.push_back(div(m));
			}
		}
		
		// print output
		if (coin) {
			for (ll j=N-1; j>=0; j--) cout << jam[j];
			for (ll i=0; i<9; i++) cout << " " << divs[i];
			cout << endl;
			J--;
		}
	}
	
	return 0;
}