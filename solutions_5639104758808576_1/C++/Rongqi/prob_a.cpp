#include <iostream>
#include <string>
using namespace std;

int testcases;
int n;

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		char ch;
		string ss;
		cin >> n >> ss;
		int s = 0;
		int o = 0;
		for (int i = 0; i <= n; i ++) {
			ch = ss[i];
			int num = (int) (ch - '0');
			if (i > 0 && num > 0) {
				if (s < i) {
					o += i - s;
					s = i;
				}
			}
			s += num;
		}
		cout << "Case #" << testcase + 1 << ": " << o << endl;
	}
	return 0;
}