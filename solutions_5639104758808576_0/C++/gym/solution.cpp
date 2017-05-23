#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

void solve(int c) {
	int len;
	string str;
	cin >> len >> str;
	int ans = 0, cur = 0;
	for (int i = 0; i <= len; i++) if (str[i] != '0') {
			if (cur < i) {
				ans += i - cur;
				cur = i;
			}
			cur += str[i] - '0';
		}
	cout << "Case #" << c << ": " << ans << endl;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve(i + 1);
	return 0;
}