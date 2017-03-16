#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

bool is_vowel(char c) {
	return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int main() {
	int n_tests;
	cin >> n_tests;
	for (int test = 0; test < n_tests; ++test) {
		string s;
		ll m;
		cin >> s >> m;
		ll n = s.size();
		ll r = 0;
		ll i = 0;
		ll p = 0;
		while (i < n) {
			while (i < n && is_vowel(s[i])) {
				++i;
			}
			if (i == n) {
				break;
			}
			ll k = 0;
			ll b = i;
			bool flag = false;
			while (i < n && !is_vowel(s[i])) {
				++k;
				if (k >= m) {
					if (!flag) {
						flag = true;
						r += (b - p + 1) * (n - i);						
					} else {
						r += (n - i);
					}
				}
				// cout << i << ' ' << s[i] << ' ' <<  r << ' ' << p << endl;
				++i;				
			}
			if (flag) {
				p = i - m + 1;
			}
		}
		cout << "Case #" << test + 1 << ": " << r << endl;
	}

	return 0;
}
