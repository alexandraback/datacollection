#include <iostream>
#include <string>

using namespace std;

int main() {
	int t; cin >> t;
	string dummy; getline(cin, dummy);
	for (int test = 1; test <= t; ++test) {
		string s; getline(cin, s);

		bool top = (s[0] == '+');
		int alternations = 0;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] != s[i + 1]) alternations++;
		}
		int cost = 0;
		while (alternations > 0 || !top) {
			bool bot = (alternations % 2 == 0) ? top : !top;
			if (bot) {
				alternations--;
			} else {
				if (top) {
					cost++; top = !top; alternations--;
				} else {
					cost++; top = !bot;
				}
			}
		}
		cout << "Case #" << test << ": " << cost << endl;
	}
	return 0;
}