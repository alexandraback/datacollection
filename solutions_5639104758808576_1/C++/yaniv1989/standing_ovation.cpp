#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t, T;
	cin >> T;
	for (t = 0; t < T; ++t) {
		int s_max;
		string s;

		cin >> s_max >> s;

		int sum = s[0]-'0';
		int res = 0;
		for (int i = 1; i <= s_max; ++i) {
			int d = s[i]-'0';
			res = max(res, i-sum);
			sum += d;
		}

		cout << "Case #" << (t+1) << ": " << res << endl;
	}
	return 0;
}