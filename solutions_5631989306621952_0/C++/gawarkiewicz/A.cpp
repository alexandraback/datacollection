#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		cin >> s;
		string out;
		for (auto& c : s) {
			if (out.empty() || c < out[0]) out += c;
			else out = c + out;
		}
		cout << "Case #" << t << ": " << out << endl;
	}
	return 0;
}