#include <iostream>
#include <string>

using namespace std;

int main() {
	int t; cin >> t;
	string dummy; getline(cin, dummy);
	for (int test = 1; test <= t; ++test) {
		string s; getline(cin, s);
		string partial = s.substr(0, 1);
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] < partial[0]) { // before
				partial.append(s.substr(i, 1));
			}
			else { // after
				partial = s.substr(i, 1) + partial;
			}
		}
		cout << "Case #" << test << ": " << partial << endl;
	}
	return 0;
}