#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T> using V = vector<T>;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> Pii;

const double Pi = acos(-1.0);

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))

/*
"ZERO",  Z
"ONE",
"TWO",   W
"THREE", T (but no TWO, and no EIGHT)
"FOUR",  U
"FIVE",  V (but no SEVEN)
"SIX",   X
"SEVEN", S (but no SIX)
"EIGHT", G
"NINE"   I (but no EIGHT, FIVE, SIX)

---
ZERO
TWO
FOUR
SIX
EIGHT
THREE
SEVEN
FIVE
NINE
ONE
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T; cin >> T;
	forn(tc, T) {
		string s;  cin >> s;
		cout << "Case #" << tc + 1 << ": ";

		int freq[26] = {};
		for (char ch : s) ++freq[ch - 'A'];
		string words[10] = {
			"ZERO", "TWO", "FOUR", "SIX", "EIGHT", "THREE", "SEVEN", "FIVE", "NINE", "ONE"
		};
		int nums[10] = {
			0, 2, 4, 6, 8, 3, 7, 5, 9, 1
		};

		vector<int> ans;

		int j = 0;
		for (string w : words) {
			int best = INT_MAX;
			for (char i = 'A'; i <= 'Z'; ++i) {
				int cnt = count(w.begin(), w.end(), i);
				if (!cnt) continue;

				best = min(best, freq[i - 'A'] / cnt);
			}

			for (char i = 'A'; i <= 'Z'; ++i) {
				int cnt = count(w.begin(), w.end(), i);

				freq[i - 'A'] -= best * cnt;
			}


			for (int i = 0; i < best; ++i) ans.push_back(nums[j]);
			j++;
		}

		sort(ans.begin(), ans.end());
		for (int i : ans) cout << i;
		cout << endl;
	}

}