#include <bits/stdc++.h>

#define _DEBUG

using namespace std;

const int N = (int)1e5 + 1;
const int inf = (int)1e9 + 7;
const int M = 261;
const int K = 10;

void solve(int test) {
	string s;
	cin >> s;
	cout << "Case #" << test << ": ";
	int answer = 1;
	for (int i = 1; i < (int)s.size(); ++i) {
		if (s[i] != s[i - 1]) {
			++answer;
		}
	}	
	if (s[(int)s.size() - 1] == '+') {
		--answer;
	}
	cout << answer << endl;
}

int main() {
#ifdef _DEBUG
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		solve(test);
	}
	return 0;
}