//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <cstdio>
#include <queue>
#include <set>
typedef long long LL;
using namespace std;
int main() {
	int T;
	string path = "/Users/baidu/Downloads/";

	//change file name
	string in = "A-small-attempt0.in";
	string out = "a.txt";

	freopen((path + in).c_str(), "r", stdin);
	freopen((path + out).c_str(), "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {

		string str;
		cin >> str;
		string ans = "";
		for (int i = 0; i < str.length(); ++i) {
			if (ans == "") {
				ans += str[i];
			} else if (ans[0] > str[i]) {
				ans += str[i];
			} else {
				ans = str[i] + ans;
			}
		}

		//output
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
