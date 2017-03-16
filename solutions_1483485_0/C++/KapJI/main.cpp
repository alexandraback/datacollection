#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const string tr = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		getline(cin, s);
		for (size_t j = 0; j < s.size(); ++j) {
			if (s[j] != ' ') {
				cout << tr[s[j] - 'a'];
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}
