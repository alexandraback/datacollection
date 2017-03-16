#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long R, C, W;
		cin >> R >> C >> W;
		long long ans = 0;
		ans += C / W;
		ans += W - 1;
		if (C % W != 0) {
			ans += 1;
		}
		ans *= R;
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
