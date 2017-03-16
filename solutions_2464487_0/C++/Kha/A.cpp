#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int ti;
	cin >> ti;
	for (int i = 0; i < ti; i++) {
		ll r, t;
		cin >> r >> t;
		ll disc = (2*r-1)*(2*r-1) + 8*t;
		ll dsqr = (ll)sqrt(disc);
		ll n = (-(2*r-1) + dsqr) / 4;
		cout << "Case #" << (i+1) << ": " << n << endl;
	}
	return 0;
}
