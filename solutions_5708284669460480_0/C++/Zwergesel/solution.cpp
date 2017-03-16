#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

bool next(int* x, int k, int s) {
	if (s == 0) return false;
	*x += 1;
	if (*x >= k) {
		*x = 0;
		return next(x+1, k, s-1);
	}
	return true;
}

void solve()
{
	int k, l, s;
	cin >> k >> l >> s;
	string kb, tw;
	cin >> kb >> tw;
	int x[s];
	for (int i=0; i<s; i++) x[i] = 0;
	int maxBanana = 0;
	int payTotal = 0;
	int words = 0;
	do {
		words++;
		int matches = 0;
		for (int i=0; i+l <= s; i++) {
			bool match = true;
			for (int j=0; j<l; j++) {
				if (kb[x[i+j]] != tw[j]) {
					match = false;
					break;
				}
			}
			if (match) {
				matches++;
				//for (int i=0; i<s; i++) cout << kb[x[i]];
				//cout << endl;
			}
		}
		maxBanana = max(matches, maxBanana);
		payTotal += matches;
	} while (next(x, k, s));
	cout << fixed << setprecision(10) << ((double) (maxBanana * words - payTotal) / words);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": " << flush;
		solve();
		cout << endl;
	}
	return 0;
}