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
#include <vector>
typedef long long LL;
using namespace std;
#define MAXN 2510
int arr[MAXN][MAXN];
int cnt[MAXN];
vector<int> res;
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
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				cnt[arr[i][j]]++;
			}
		}
		res.clear();
		for (int i = 0; i < MAXN; i++) {
			if (cnt[i] & 1) {
				res.push_back(i);
			}
		}

		//output
		//cout << "Case #" << t << ": " << ans << endl;
		cout << "Case #" << t << ":";
		for (int i = 0; i < res.size(); i++) {
			cout << " " << res[i];
		}
		cout << endl;
	}
	return 0;
}
