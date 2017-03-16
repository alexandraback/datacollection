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
#define MAXN 3010
int dp[MAXN][MAXN];
int f[MAXN];
int g[MAXN];
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
		LL n;
		LL ans;
		cin >> n;
		if (n == 0) {
			ans = -1;
		} else {
			set<int> myset;
			LL add = n;
			while (myset.size() < 10) {
				for (LL tmp = n; tmp; tmp /= 10) {
					myset.insert(tmp % 10);
				}
				n += add;
			}
			ans = n - add;
		}
		//output
		if (ans < 0) {
			cout << "Case #" << t << ": " << "INSOMNIA" << endl;
		} else {
			cout << "Case #" << t << ": " << ans << endl;
		}
	}
	return 0;
}
