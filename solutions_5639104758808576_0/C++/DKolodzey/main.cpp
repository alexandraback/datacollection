#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		long long s_max;
		cin >> s_max;
		long long already_up = 0;
		long long friends = 0;
		for (long long s = 0; s <= s_max; ++s) {
			char ch;
			cin >> ch;
			long long cur = (ch - '0');
			if (s > already_up) {
				friends += (s - already_up);
				already_up += (s - already_up);
			}
			already_up += cur;
		}
		cout << "Case #" << t << ": " << friends << endl;
	}
	return 0;
}