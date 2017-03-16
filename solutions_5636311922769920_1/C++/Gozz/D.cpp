#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << (t+1) << ":";
		i64 K, C, S;
		cin >> K >> C >> S;
		if (C * S < K) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		i64 k = 0;
		while (k < K) {
			i64 r = 0;
			for (i64 c = 0; c < C; ++c) {
				r *= K;
				if (k < K) r += k++;
			}
			cout << " " << (r+1);
		}
		cout << endl;
	}
	return 0;
}