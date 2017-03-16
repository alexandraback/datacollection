#include <bits/stdtr1c++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    for (int ca = 1; ca <= t; ca++) {
		int k, c, s; cin >> k >> c >> s;
        cout << "Case #" << ca << ": ";
		if ((k+c-1)/c > s) cout << "IMPOSSIBLE" << endl;
		else {
			//want 1 + 2k + 3k^2 + ... + c * k^c
			if (c >= k) {
				ll res = 0, b = 1;
				for (int i = 0; i < k; i++) {
					res += i * b;
					b *= k;
				}
				cout << res + 1 << endl;
			} else {
				bool first = true;
				for (int j = 0; j < k; j+=c) {
					ll res = 0, b = 1;
					for (int i = 0; i < c; i++) {
						res += min(k-1, i + j) * b;
						b *= k;
					}
					
					if (!first) cout << " ";
					cout << res + 1;
					first = false;
				}
				cout << endl;
			}
		}
    }
	return 0;
}