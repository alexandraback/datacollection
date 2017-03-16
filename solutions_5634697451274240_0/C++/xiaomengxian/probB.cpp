#include <iostream>
#include <string>
using namespace std;
int testcases;

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		string s;
		cin >> s;
		int ans = 1;
		for (int i = 1; i < s.size(); i ++) {
			if (s[i] != s[i - 1]) {
				ans ++;
			}
		}
		if (s[s.size() - 1] == '+') {
			ans --;
		}
		cout << "Case #" << testcase + 1 << ": " << ans << endl;
	}
	return 0;
}