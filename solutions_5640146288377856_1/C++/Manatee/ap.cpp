#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int itest = 1; itest <= T; ++itest) {
		long long r, c, w;
		long long ans;

		cin >> r >> c >> w;
		if (w == 1) {
			ans = r * c;
		}
		else if (c % w == 0) {
			ans = (c) / w * r + w - 1;
		}
		else {
			ans = (c) / w * r + w;

		}
		cout << "Case #" << itest << ": " << ans << "\n";
	}
	return 0;
}
