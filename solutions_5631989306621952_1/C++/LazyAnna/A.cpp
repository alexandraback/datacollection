#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int tests, n;
	string str;
	int a[10];
	int sum;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> str;
		string ans = "";
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] + ans < ans + str[i]) {
				ans = ans + str[i];
			} else {
				ans = str[i] + ans;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	// sort(a, a + d);
	return 0;
}