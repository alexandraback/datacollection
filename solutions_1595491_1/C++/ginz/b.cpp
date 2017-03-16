#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int n, s, p, t, ans = 0;
		cin >> n >> s >> p;
		for (int j = 0; j < n; ++j) {
			cin >> t;
			if (t % 3 == 1)
				ans += ((t / 3) + 1 >= p);
			else if (t % 3 == 2) {
				if ((t / 3) + 1 >= p)
					++ans;
				else if ((t / 3) + 2 >= p && s > 0)
					++ans, --s;
			} else {
				if (t / 3 >= p)
					++ans;
				else if (t > 0 && (t / 3) + 1 >= p && s > 0)
					++ans, --s;
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}
