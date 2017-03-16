#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include<functional>
#include <fstream>
#define ii pair<int,int>
#define INF 1000000000
using namespace std;

int power(int b, int i, int j) {
	int ans = b%j;
	b = 1;
	if (i == 0)
		return 1;
	for (int x = 0; x < i; x++) {
		b *= ans;
		b %= j;
	}
	return b;
}

long long getBase(string s, int b) {
	for (int j = 2; j <= 11; j++) {
		int sol = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1')
				sol += power(b, i, j) % j;
			sol %= j;
		}
		if (sol == 0)
			return j;
	}
	return 0;
}
int n, j;
int cnt = 0;
void rec(string s) {
	if (cnt == j)
		return;
	if (s.size() == 0) {
		rec(s + '1');
		return;
	}
	if (s.size() == n - 1) {
		s += '1';
		vector <int> ans;
		for (int i = 2; i <= 10; i++) {
			long long y = getBase(s, i);
			if (y) {
				ans.push_back(y);
			}
		}
		if (ans.size() == 9 && cnt < j) {
			for (int i = s.size() - 1; i >= 0; i--)
				cout << s[i];
			cout << ' ';
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << ' ';
			}
			cout << endl;
			cnt++;
		}
		ans.clear();
		return;
	}
	rec(s + '0');
	rec(s + '1');
}

int main() {
	freopen("output2.txt", "w", stdout);
	int t;
	cin >> t;
	for (int l = 0; l < t; l++) {
		cnt = 0;
		string s;
		cin >> n >> j;
		cout << "Case #1:" << endl;
		rec(s);
	}

	return 0;
}
