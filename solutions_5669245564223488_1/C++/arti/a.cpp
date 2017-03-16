#include <iostream>
#include <cstring>
#include <string>

using namespace std;

typedef long long i64;

const int P = 1000000007;

string s[1000];
int d[26][26];
int e[26];
i64 f[1000];

int main() {
	int T;
	cin >> T;
	f[0] = 1;
	for (int i = 1; i < 1000; ++i) {
		f[i] = (f[i - 1] * i) % P;
	}
	for (int tt = 0; tt < T; ++tt) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		memset(d, 0, sizeof(d));
		memset(e, 0, sizeof(e));
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			int c = 0;
			bool u[26];
			memset(u, 0, sizeof(u));
			for (int j = 0; j < s[i].length(); ++j) {
				if (!j || s[i][j] != s[i][j - 1]) {
					if (u[s[i][j] - 'a']) {
						ok = false;
						break;
					}
					u[s[i][j] - 'a'] = true;
					++c;
				}
			}
			if (!ok) break;
			if (c > 2) {
				int j = 0;
				while (s[i][j] == s[i][0]) ++j;
				while (s[i][j] != s[i][s[i].length() - 1]) {
					if (s[i][j] != s[i][j - 1]) {
						for (int k = 0; k < n; ++k) if (k != i) {
							if (s[k].find(s[i][j]) != string::npos) {
								ok = false;
								break;
							}
						}
						if (!ok) break;
					}
					++j;
				}
				if (!ok) break;
			}
			if (c >= 2) {
				++d[s[i][0] - 'a'][s[i][s[i].length() - 1] - 'a'];
			} else if (c == 1) {
				++e[s[i][0] - 'a'];
			}
		}
		i64 r1 = 0;
		i64 r2 = 0;
		i64 r3 = 0;
		if (ok) {
			for (int i = 0; i < 26; ++i) {
				int w1 = 0;
				for (int j = 0; j < 26; ++j) {
					//if (d[i][j]) cout << i << " " << j << " " << d[i][j] << endl;
					w1 += d[i][j];
				}
				if (w1 > 1) {
					ok = false;
					break;
				}
				int w2 = 0;
				for (int j = 0; j < 26; ++j) {
					w2 += d[j][i];
				}
				if (w2 > 1) {
					ok = false;
					break;
				}
				if (w1 == 1 && w2 == 0) {
					++r1;
				}
				if (e[i] && w1 == 0 && w2 == 0) {
					++r2;
				}
				if (w1 > 0 && w2 > 0) {
					++r3;
				}
			}
			if (!r1 && r3 > 0) {
				ok = false;
			}
		}
		i64 r = r1 + r2;
		// cout << r << endl;
		if (ok) {
			r = f[r];
			for (int i = 0; i < 26; ++i) {
				r *= f[e[i]];
				r %= P;
			}
		} else {
			r = 0;
		}
		printf("Case #%d: %lld\n", tt + 1, r);
	}
	return 0;
}
