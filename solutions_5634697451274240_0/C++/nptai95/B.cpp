#include <iostream>
#include <string>

using namespace std;
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string str;
		cin >> str;
		int cnt = 0;
		char last = '2';
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] != last) {
				last = str[i];
				cnt++;
			}
		}

		if (last == '+')
			cnt--;

		cout << "Case #" << t << ": " << cnt << endl;
	}
}