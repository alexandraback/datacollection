#include <bits/stdc++.h>

using namespace std;

string S;

char flip(char c) {
	return c == '+' ? '-' : '+';
}

void flipRange(int st, int dr) {
	reverse(S.begin() + st, S.begin() + dr + 1);
	for (int i = st; i <= dr; i++) {
		S[i] = flip(S[i]);
	}
}

int solve() {
	int N = (int) S.size();
	int ans = 0;

	int st = 0;
	int dr = N - 1;
	while (st <= dr) {
		if (S[dr] == '+') {
			dr--;
		} else if (S[st] == '+') {
			int pos = st;
			while (pos + 1 <= dr && S[pos + 1] == '+') {
				pos++;
			}
			flipRange(st, pos);
			ans++;
		} else {
			flipRange(st, dr);
			ans++;
		}
	}

	return ans;
}

int main() {
	assert(freopen("B.in", "r", stdin));
	assert(freopen("B.out", "w", stdout));
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		cin >> S;
		int ans = solve();
		cout << ans << '\n';
		
		cerr << t << endl;
	}

	return 0;
}
