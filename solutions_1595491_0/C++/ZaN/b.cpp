#include <iostream>
using namespace std;

int main() {
	int test_count;
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		int n, s, p;
		cin >> n >> s >> p;
		int c1 = 0, cs = 0;
		for (int i = 0; i < n; ++i) {
			int k;
			cin >> k;
			int a = k / 3;
			switch (k % 3) {
			case 0:
				if (a >= p) {
					++c1;
				} else if (a >= 1 && a == p - 1) {
					++cs;
				}
				break;
			case 1:
				if (a >= p - 1) {
					++c1;
				}
				break;
			case 2:
				if (a >= p - 1) {
					++c1;
				} else if (a == p - 2) {
					++cs;
				}
			}
		}

		int ans = min(s, cs) + c1;
		cout << "Case #" << test << ": " << ans << endl;
	}
}
