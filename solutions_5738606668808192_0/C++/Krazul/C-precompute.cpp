#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, j;
int jam_id = 0;

ll interp(ll mask, int base) {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans *= base;
		if (mask % 2 == 1) ans++;
		mask /= 2;
	}
	return ans;
}

void print_mask(ll mask) {
	for (int i = 0; i < n; ++i) {
		cout << mask % 2;
		mask /= 2;
	}
}

int main() {
	int t; cin >> t;
	for (int test = 1; test <= t; ++test) {
		cin >> n >> j;
		for (ll mask = 0; mask < (1 << n); ++mask) {
			if ((mask & 1) && (mask & (1 << (n - 1)))) { // jamcoin must start with 1 and end with 1
				vector<int> divisors(11);
				int divisors_found = 0;
				for (int base = 2; base <= 10; ++base) {
					ll n = interp(mask, base);
					for (ll i = 2; i * i < n; ++i) {
						if (n % i == 0) {
							divisors[base] = i;
							divisors_found++;
							break;
						}
					}
					if (divisors_found < base - 1) break;
				}
				if (divisors_found == 9) {
					cout << "coin[" << jam_id << "] = \"";
					print_mask(mask);
					cout << "\";" << endl;

					for (int base = 2; base <= 10; ++base) {
						cout << "arr[" << jam_id << "][" << base - 2 << "] = " << divisors[base] << ";" << endl;
					}

					jam_id++;
				}
			}
		}
	}
	return 0;
}