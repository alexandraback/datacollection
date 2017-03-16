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
	string in = "B-small-attempt0.in";
	string out = "b.txt";

	freopen((path + in).c_str(), "r", stdin);
	freopen((path + out).c_str(), "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string str;
		cin >> str;
		string tmp;
		for (int i = 0; i < str.length(); ++i) {
			if (i == 0 || str[i] != str[i - 1]) {
				tmp += str[i];
			}
		}

		int ans = tmp.length();
		if (tmp[tmp.length() - 1] == '+') {
			--ans;
		}

		//output
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
