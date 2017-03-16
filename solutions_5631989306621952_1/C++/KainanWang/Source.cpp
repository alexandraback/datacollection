#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void solve(int test) {
	char s[1009];
	cin >> s;
	string res = "";
	for (int i = 0; s[i]; ++i) {
		if (res.length() == 0 || s[i] >= res[0]) {
			res = s[i] + res;
		}
		else {
			res += s[i];
		}
	}
	cout << "Case #" << test << ": " << res << endl;
}

int main() {
//	freopen("test.in", "r", stdin);
//	freopen("test.our", "w", stdout);
	int testNumber;
	cin >> testNumber;
	for (int test = 1; test <= testNumber; ++test) {
		solve(test);
	}
}