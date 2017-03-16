#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		i64 B, M;
		cin >> B >> M;
		if (M <= (1 << (B-2))) {
			cout << "Case #" << t << ": POSSIBLE" << endl;
			for (int b = B-2; b >= 0; --b)
				cout << (((M-1) >> b) & 1);
			cout << 1 << endl;
			for (int b = 1; b < B; ++b) {
				for (int i = 0; i < B; ++i)
					cout << (i <= b ? 0 : 1);
				cout << endl;
			}
		} else {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		}
	}
}