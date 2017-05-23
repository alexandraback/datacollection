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

long long getBase(string s, int b) {
	long long sol = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1')
			sol += pow(b, i);
	}
	return sol;
}

long long prime(long long x) {
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return i;
	}
	return 0;
}

int main() {
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int l = 0; l < t; l++) {
		vector<int> ans;
		int cnt = 0;
		int n, j;
		cin >> n >> j;
		cout << "Case #1:" << endl;
		int left = pow(2, n - 1) + 1, r = pow(2, n) - 1;
		while (left <= r) {
			string s;
			int x = left;
			while (x > 0) {
				if (x % 2 == 1)
					s += '1';
				else
					s += '0';
				x /= 2;
			}
			for (int i = 2; i <= 10; i++) {
				long long y = getBase(s, i);
				long long m = prime(y);
				if (m) {
					ans.push_back(m);
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
			if (cnt == j)
				break;
			ans.clear();
			left += 2;
		}
	}

	return 0;
}
