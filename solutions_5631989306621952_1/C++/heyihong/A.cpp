#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int test_cases;
	cin >> test_cases;
	for (int tc = 1; tc <= test_cases; ++tc) {
		string s;
		cin >> s;
		string t = s;
		vector<int> di(s.size(), 1);
		for (char c = 'Z'; c >= 'A'; --c) {
			int first_pos = t.size();
			for (int i = t.size() - 1; i != -1; --i) {
				if (t[i] == c) {
					first_pos = i;
					di[i] = 0;
				}
			}
			t = t.substr(0, first_pos);
		}
		string res = "";
		for (int i = 0; i != s.size(); ++i) {
			if (di[i] == 0) {
				res = s[i] + res;
			} else {
				res = res + s[i];
			}
		}
		cout << "Case #" << tc << ": " << res << endl;
	}
	return 0;
}
