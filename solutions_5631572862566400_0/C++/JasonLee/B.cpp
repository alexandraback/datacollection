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
#include <cmath>
typedef long long LL;
using namespace std;
#define MAXN 3010
int bbf[MAXN];
bool ok[MAXN][MAXN];
int one(int x) {
	int ans = 0;
	while (x) {
		ans += x & 1;
		x >>= 1;
	}
	return ans;
}
bool check(int s, int n) {
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		if (s & (1 << i)) {
			arr.push_back(1 + i);
		}
	}
	sort(arr.begin(), arr.end());
	do {
		bool flag = true;
		int size = arr.size();
		for (int i = 0; i < size; i++) {
			int l = (i - 1 + size) % size;
			int r = (i + 1) % size;
			//	cout << arr[l] << "," << arr[i] << "," << arr[r] << endl;
			if (ok[arr[i]][arr[l]] || ok[arr[i]][arr[r]]) {
				continue;
			} else {
				flag = false;
				break;
			}
		}
		//	cout << "   ffff " << endl;
		if (flag) {
			return true;
		}
	} while (next_permutation(arr.begin(), arr.end()));
	return false;
}
int main() {
	int T;
	string path = "/Users/baidu/Downloads/";

//change file name
	string in = "C-small-attempt1.in";
	string out = "f.txt";

	freopen((path + in).c_str(), "r", stdin);
	freopen((path + out).c_str(), "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {

		memset(ok, false, sizeof(ok));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> bbf[i];
			ok[i][bbf[i]] = true;
		}

		int ans = 0;
		//puts("1");
		for (int i = 1; i < (1 << n); ++i) {
			if (check(i, n)) {
				ans = max(ans, one(i));
			}
		}

		//output
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
