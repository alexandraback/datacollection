#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;

int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool check(const string& s) {
	int sz = s.size();
	int vis[128];
	memset(vis, 0, sizeof(vis));
	vis[s[0]] = 1;
	//cout << s << "\n";
	for (int i = 1; i < sz; i ++) {
		if (s[i] != s[i - 1]) {
			if (vis[s[i]]) {
				return false;
			} else {
				vis[s[i]] = 1;
			}
		}
	}
	return true;
}

int solve(const vector<string> & vec) {
	int n = vec.size();
	for (int i = 0; i < n; i ++) {
		num[i] = i;
	}
	int cnt = 0;
	do {
		string s = "";
		for (int i = 0; i < n; i ++) {
			s += vec[num[i]];
		}
		if (check(s)) {
			cnt ++;
		}
	} while (next_permutation(num, num + n));
	return cnt % MOD;
}

int main(int argc, char *argv[]) {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.txt", "w", stdout);
	int cas;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		int n;
		string str, word;
		vector<string> vec;
		cin >> n;
		cin.get();
		getline(cin, str);
		stringstream ssin(str);
		while (ssin >> word) {
			vec.push_back(word);
		}
		int ans = solve(vec);
		cout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}
