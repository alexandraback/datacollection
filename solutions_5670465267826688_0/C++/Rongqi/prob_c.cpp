#include <iostream>
#include <string>
using namespace std;

int testcases;
int n, m;
string s;
bool o;

int conv(char ch) {
	if (ch == 'i') return 2;
	if (ch == 'j') return 3;
	if (ch == 'k') return 4;
	return 0;
}

int calc(int a, int b) {
	if (a == 1 || a == -1) return a * b;
	if (b == 1 || b == -1) return a * b;
	int sgn = 1;
	if (a < 0) {
		sgn = -sgn;
		a = -a;
	}
	if (b < 0) {
		sgn = -sgn;
		b = -b;
	}
	int res = 0;
	if (a == 2) {
		if (b == 2) {
			res = -1;
		} else if (b == 3) {
			res = 4;
		} else if (b == 4) {
			res = -3;
		}
	} else if (a == 3) {
		if (b == 2) {
			res = -4;
		} else if (b == 3) {
			res = -1;
		} else if (b == 4) {
			res = 2;
		}
	} else if (a == 4) {
		if (b == 2) {
			res = 3;
		} else if (b == 3) {
			res = -2;
		} else if (b == 4) {
			res = -1;
		}
	}
	return res * sgn;
}

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		cin >> n >> m;
		if (m >= 8) {
			m = m % 4 + 8;
		}
		cin >> s;

		o = false;

		int now = 1;
		for (int i = 0; i < s.size(); i ++) {
			now = calc(now, conv(s[i]));
		}
//		cout << now << endl;
		int tot = 1;
		for (int i = 0; i < m; i ++) {
			tot = calc(tot, now);
		}
//		cout << tot << endl;

		if (tot == -1) {
			int target = 2;
			int now = 1;
			for (int i = 0; i < s.size() * m; i ++) {
				now = calc(now, conv(s[i % s.size()]));
//				cout << now << " ";
				if (now == target) {
//					cout << "!";
					now = 1;
					target ++;
					if (target > 4) {
						o = true;
						break;
					}
				}
			}
//			cout << endl;

		}


		cout << "Case #" << testcase + 1 << ": ";
		if (o) {
			cout << "YES";
		} else {
			cout << "NO";
		}

		cout << endl;
	}

	return 0;
}