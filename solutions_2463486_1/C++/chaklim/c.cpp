#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

ll t;
ll a, b;
const ll l = 100000000000005;
vector<ll> v;

ll ri(ll a) {
	ll n = 0;
	while (a) {
		n *= 10;
		n += a % 10;
		a /= 10;
	}
	return n;
}

void preprocess() {
	v.clear();
	ll l2 = (ll)sqrt(l + 0.0);
	ll t2;
	for (ll i = 1; i <= l2; i++) {
		t2 = ri(i);
		if (i == t2) {
			t2 = i * i;
			if (t2 == ri(t2))
				v.push_back(t2);
		}
	}
}

int main() {
	preprocess();

	cin >> t;

	int c = 0;
	while (t--) {
		printf("Case #%d: ", ++c);

		cin >> a >> b;

		ll c2 = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] >= a && v[i] <= b)
				c2++;
		}

		cout << c2 << endl;
	}	

	return 0;
}
