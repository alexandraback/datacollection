#pragma comment(linker, "/stack:8388608")
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cassert>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++) {
		string s;
		int n;
		cin >> s >> n;

		int cnt = 0;
		ll ans = 0;
		int last = -1;
		for (int i = 0; i < (int)s.length(); i++) {
			if (!isVowel(s[i]))
				++cnt;
			else {
				if (cnt >= n) {
					ans += 1ll * (i - n - last) * ((int)s.length() - i);
					last = i - n;
				}
				cnt = 0;
			}

			if (cnt >= n) {
				ans += i - n + 1 - last;
			}
		}

		cout << "Case #" << (test + 1) << ": " << ans << endl;
	}

	return 0;
}