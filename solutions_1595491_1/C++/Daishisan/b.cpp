#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		int ans = 0;
		int n, s, p; cin >> n >> s >> p;
		for (int i = 0; i < n; ++i) {
			int curr; cin >> curr;
			if (curr >= 3*p - 2)
				++ans;
			else if (s > 0 && curr >= 3*p - 4 && p > 1) {
				++ans;
				--s;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}

