#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

typedef long long i64;

const int P = 1000000007;

string s[1000];
int d[26][26];
int e[26];
i64 f[1000];
int a[1000];

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
		for (int i = 0; i < n; ++i) {
			a[i] = i;
		}
		i64 r = 0;
		do {
			bool u[26];
			memset(u, 0, sizeof(u));
			int last = 0;
			bool ok = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < s[a[i]].length(); ++j) {
					if (s[a[i]][j] != last) {
						if (u[s[a[i]][j] - 'a']) {
							ok = false;
							break;
						}
						u[s[a[i]][j] - 'a'] = true;
						last = s[a[i]][j];
					}
				}
				if (!ok) break;
			}
			if (ok) ++r;
		} while (next_permutation(a, a + n));
		printf("Case #%d: %lld\n", tt + 1, r);
	}
	return 0;
}
