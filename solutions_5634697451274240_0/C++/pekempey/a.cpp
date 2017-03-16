#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
	int result = 0;

	int i = 0;
	char last = 0;
	while (i < s.length()) {
		result++;
		last = s[i];

		int j = i;
		while (i < s.length() && s[i] == s[j]) i++;
	}
	if (last == '+') result--;

	return result;
}

int main() {
	int T;
	cin >> T;
	for (int ii = 1; ii <= T; ii++) {
		string s;
		cin >> s;
		int ans = solve(s);

		printf("Case #%d: %d\n", ii, ans);
	}
}