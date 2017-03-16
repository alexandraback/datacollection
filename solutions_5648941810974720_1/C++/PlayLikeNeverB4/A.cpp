#include <bits/stdc++.h>

using namespace std;

string LETTERS[] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

string S;
int f[26];
int cnt[10];

void removeLetters(int d) {
	string &s = LETTERS[d];
	int dCount = cnt[d];
	for (size_t i = 0; i < s.size(); i++) {
		int p = s[i] - 'A';
		f[p] -= dCount;
		assert(f[p] >= 0);
	}
}

string solve() {
	memset(f, 0, sizeof(f));
	int n = (int) S.size();
	for (int i = 0; i < n; i++) {
		f[S[i] - 'A']++;
	}

	memset(cnt, 0, sizeof(cnt));
	cnt[0] = f['Z' - 'A'];
	cnt[2] = f['W' - 'A'];
	cnt[4] = f['U' - 'A'];
	cnt[6] = f['X' - 'A'];
	cnt[8] = f['G' - 'A'];
	removeLetters(0);
	removeLetters(2);
	removeLetters(4);
	removeLetters(6);
	removeLetters(8);

	cnt[1] = f['O' - 'A'];
	cnt[3] = f['H' - 'A'];
	cnt[5] = f['F' - 'A'];
	removeLetters(1);
	removeLetters(3);
	removeLetters(5);

	cnt[7] = f['S' - 'A'];
	removeLetters(7);

	cnt[9] = f['I' - 'A'];
	removeLetters(9);

	string ret = "";
	for (int d = 0; d < 10; d++) {
		// cerr << cnt[d] << endl;
		// cerr << string(cnt[d], (char) (d + '0')) << endl;
		ret += string(cnt[d], (char) (d + '0'));
	}

	return ret;
}

int main() {
	assert(freopen("A.in", "r", stdin));
	assert(freopen("A.out", "w", stdout));
	cin.sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";

		cin >> S;
		string ans = solve();
		cout << ans << '\n';

		cerr << t << endl;
	}

	return 0;
}
