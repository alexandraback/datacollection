#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		char str[128];
		cin >> str;

		int ans = 0;
		for (int i = 0; str[i]; i++) {
			if (str[i + 1])
				ans += (int)(str[i] != str[i + 1]);
			else
				ans += (int)(str[i] == '-');
		}

		cout << ans << endl;
	}

	return 0;
}
