#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;

		string res = "";
		res = res + s[0];
		for (int i = 1; i < s.length(); i++) {
			if (s[i] < res[0])
				res = res + s[i];
			else
				res = s[i] + res;
		}

		cout << "Case #" << tc << ": " << res << endl;
	}
	return 0;
}