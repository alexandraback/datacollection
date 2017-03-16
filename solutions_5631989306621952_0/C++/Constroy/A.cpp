#include <iostream>
#include <string>

using namespace std;

int T;
string s, t;

int main() {
	cin >> T;
	for (int iT = 1; iT <= T; ++iT) {
		cout << "Case #" << iT << ": ";
		cin >> s;
		t.clear();
		for (auto c: s) {
			if (t.empty() || c < t.front()) t += c;
			else t = c + t;
		}
		cout << t << endl;
	}
	return 0;
}
