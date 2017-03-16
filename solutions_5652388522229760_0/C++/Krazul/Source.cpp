#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

void push_digits_to_set(ll x, set<int>& histo) {
	while (x > 0) {
		histo.insert(x % 10);
		x /= 10;
	}
}

int main() {
	int t; cin >> t;
	for (int test = 1; test <= t; ++test) {
		ll n; cin >> n;
		if (n == 0) {
			cout << "Case #" << test << ": INSOMNIA" << endl;
			continue;
		}

		int i = 0;
		set<int> histo;
		while (histo.size() != 10) {
			i += n;
			push_digits_to_set(i, histo);
		}
		cout << "Case #" << test << ": " << i << endl;
	}
	return 0;
}