#include <iostream>
using namespace std;

int bff[10000];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string inp;
		string outp;

		cin >> inp;

		char firstdiff = 0;
		for (char c : inp) {
			if (outp.empty()) {
				outp.push_back(c);
				continue;
			}
			if (c != outp[0]) {
				if (c < outp[0]) {
					if (!firstdiff) firstdiff = c;
					outp.push_back(c);
				} else {
					firstdiff = outp[0];
					outp = string(1, c) + outp;
				}
			} else {
				if (c < firstdiff) outp.push_back(c);
				else outp = string(1, c) + outp;
			}
		}

		cout << "Case #" << t << ": " << outp << '\n';
	}

	return 0;
}
