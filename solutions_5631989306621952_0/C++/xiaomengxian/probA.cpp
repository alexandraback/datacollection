#include <iostream>
#include <string>
using namespace std;
int testcases;

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		string ans;
		string s;
		cin >> s;
		ans += s[0];
		for (int i = 1; i < s.size(); i ++) {
			if (s[i] + ans > ans + s[i]) {
				ans = s[i] + ans;
			} else {
				ans = ans + s[i];
			}
		}
		cout << "Case #" << testcase + 1 << ": " << ans << endl;
	}
	return 0;
}