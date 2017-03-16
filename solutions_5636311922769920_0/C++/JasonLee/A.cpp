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
	string in = "D-small-attempt0.in";
	string out = "d.txt";

	freopen((path + in).c_str(), "r", stdin);
	freopen((path + out).c_str(), "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int k, c, s;
		cin >> k >> c >> s;

		//output
		//cout << "Case #" << t << ": " << ans << endl;
		cout << "Case #" << t << ":";
		for (int i = 1; i <= s; ++i) {
			cout << " " << i;
		}
		cout << endl;
	}
	return 0;
}
