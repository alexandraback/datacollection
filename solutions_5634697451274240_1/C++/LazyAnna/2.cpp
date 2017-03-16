#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests, n;
	int a[10];
	string s;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> s;
		string ss = "";
		ss += s[0];
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != s[i - 1]) {
				ss += s[i];
			}
		}
		int count = 0;
		while (ss != "+") {
			if (ss[0] == '+') {
				ss = ss.substr(1);
				++count;
			} else {
				int j = ss.size() - 1;
				while ((j > 0) && (ss[j] == '+')) {
					--j;
				}
				string sss = "";
				for (int k = 0; k <= j; ++k) {
					if (ss[j - k] == '+') {
						sss += "-";
					} else {
						sss += "+";
					}
				}
				sss += ss.substr(j + 1);
				ss = "";
				ss += sss[0];
				for (int i = 1; i < sss.size(); ++i) {
					if (sss[i] != sss[i - 1]) {
						ss += sss[i];
					}
				}
				++count;
			}
		} 
		cout << "Case #" << t << ": " << count << endl;		
	}
	return 0;
}