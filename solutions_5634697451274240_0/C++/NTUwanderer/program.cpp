#include <iostream>

using namespace std;

int main() {
	int round = 0, counter = 0, ans = 0;
	bool start = false, period = false;
	string s = "";
	
	cin >> round;

	for (int k = 0; k < round; ++k) {
		cin >> s;

		if (s.length() == 0)
			cout << "Case #" << k + 1 << ": " << 0 << endl;
		else {
			start = period = (s[0] == '+');
			for (int i = 1, length = s.length(); i < length; ++i) {
				if (period != (s[i] == '+')) {
					period = !period;
					++counter;
				}
			}
			int ans = 2 * (counter / 2);
			if (start)	ans = 2 * ((counter + 1) / 2);
			else		ans = 1 + 2 * (counter / 2);
			cout << "Case #" << k + 1 << ": " << ans << endl;
		}
		counter = 0;
	}
	return 0;
}