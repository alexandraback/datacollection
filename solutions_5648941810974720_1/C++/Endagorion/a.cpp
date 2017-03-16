#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef pair<int, int> pii;

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ord[10] = {4, 5, 0, 7, 6, 2, 8, 1, 3, 9};

int main() {
	cout.precision(10);
	cout << fixed;
	int T;
	cin >> T;
	for1(tt, T) {
		string s;
		cin >> s;
		vi cnt(26);
		for (char c: s) ++cnt[c - 'A'];
		string ans;
		forn(i, 10) {
			int d = ord[i];
			bool done = false;
			while (!done) {
				for (char c: digits[d]) {
					--cnt[c - 'A'];
				}
				if (*min_element(all(cnt)) < 0) {
					for (char c: digits[d]) {
						++cnt[c - 'A'];
					}
					done = true;
				} else ans += (char)('0' + d);
			}
		}
		assert(cnt == vi(26, 0));
		sort(all(ans));
		cout << "Case #" << tt << ": " << ans << '\n';
	}
}
