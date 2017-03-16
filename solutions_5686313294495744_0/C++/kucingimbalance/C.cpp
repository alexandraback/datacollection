#include <bits/stdc++.h>

using namespace std;

#define MAXN 16

int main() {
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		int n;
		string a[MAXN+5], b[MAXN+5];
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}

		int ans = 0;
		for (int i = 0; i < (1<<n); ++i) {
			set<string> fwords, swords;

			for (int j = 0; j < n; ++j) {
				if (i & (1<<j)) {
					fwords.insert(a[j]);
					swords.insert(b[j]);
				}
			}
			
			int ok = 1;
			int bits = 0;
			for (int j = 0; j < n; ++j) {
				if (i & (1<<j)) {}
				else {
					if (fwords.find(a[j]) == fwords.end() ||
							swords.find(b[j]) == swords.end()) {
						ok = false;
					}
					++bits;
				}
			}
			if (ok) ans = max(ans, bits);
		}
		printf("Case #%d: %d\n", itc, ans);
	}
	return 0;
}
