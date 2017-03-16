#include <iostream>
#include <string>

using namespace std;

char a[] = "aeiou";

bool isBad(char c) {
	for (int i = 0; i < 5; ++i) {
		if (c == a[i]) return true;
	}
	return false;
}

long long gao(const string &s, int n) {
	long long ret = 0;
	int cnt = 0;
	int nearest = -1;
	for (int i = 0; i < s.length(); ++i) {
		if (!isBad(s[i])) {
			++cnt;
		} else {
			cnt = 0;
		}
		
		if (cnt >= n) {
			nearest = i - n + 1;
		}
		ret += nearest + 1;
	}
	return ret;
}

int main() {
	int Tc;
	cin >> Tc;
	string s;
	int n;
	for (int re = 1; re <= Tc; ++re) {
		cin >> s >> n;
		cout << "Case #" << re << ": " << gao(s, n) << endl;
	}
	return 0;
}
