#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int lmax = 1E6;
string s;
int cn[lmax + 1]; //, nn[lmax + 1];

bool vow(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	int nt, it;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int n, i, add = 0;
		ll r = 0;

		cin >> s >> n;
		for (i = 0; i < s.size(); i++) {
			cn[i] = vow(s[i]) ? 0 : (i ? cn[i - 1] : 0) + 1;
			if (cn[i] >= n) add = i - n + 2;
			// cout << i << ':' << add << '\n';
			r += add;
		}
		cout << "Case #" << it << ": " << r << endl;
	}
}
