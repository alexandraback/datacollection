#include <iostream>
#include <fstream>
#include <set>

using namespace std;

typedef long long ll;

ll tens[10];

int digits (ll n) {
	int ans = 0;
	for (; n; ++ans, n /= 10);
	return ans;
}

int shift (ll n, int sh, int dig) {
	return (n / tens[sh]) + (n % tens[sh]) * tens[dig - sh];;
}

int main() {
	int T;
	ll cur = 1;
	for (int i = 0; i < 10; ++i) {
		tens[i] = cur;
		cur *= 10;
	}
	cin >> T;
	for (int i = 0; i < T; ++i) {
		ll a, b, ans = 0;
		cin >> a >> b;
		for (ll n = a; n < b; ++n) {
			int dig = digits (n);
			set <int> recycles;
			for (int sh = 1; sh < dig; ++sh) {
				int recycle = shift (n, sh, dig);
				if (recycle > n && recycle <= b)
					recycles.insert (recycle);
			}
			ans += recycles.size ();
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}
