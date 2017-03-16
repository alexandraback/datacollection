#include <iostream>
#include <vector>
using namespace std;

int m[8][8] = {
	{ 0, 1, 2, 3, 4, 5, 6, 7 },
	{ 1, 4, 3, 6, 5, 0, 7, 2 },
	{ 2, 7, 4, 1, 6, 3, 0, 5 },
	{ 3, 2, 5, 4, 7, 6, 1, 0 },
	{ 4, 5, 6, 7, 0, 1, 2, 3 },
	{ 5, 0, 7, 2, 1, 4, 3, 6 },
	{ 6, 3, 0, 5, 2, 7, 4, 1 },
	{ 7, 6, 1, 0, 3, 2, 5, 4 } };

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int l;
		long long x;
		cin >> l >> x;
		int rep = 4;
		if (rep > x) {
			rep = x;
		}

		vector<int> s(rep*l);
		int mul = 0;  // 0 -> 1
		for (int i = 0; i < l; ++i) {
			char c;
			cin >> c;
			s[i] = (c - 'i' + 1);  // i -> 1, j -> 2, k -> 3
			for (int r = 1; r < rep; ++r) {
				s[i + r*l] = s[i];
			}
			mul = m[mul][s[i]];
		}

		long long xx = x % 4;
		int mulf = 0;  // 0 -> 1
		for (int i = 0; i < xx; ++i) {
			mulf = m[mulf][mul];
		}
		if (mulf != 4) {  // 4 -> -1
			cout << "Case #" << test << ": NO" << endl;
			continue;
		}

		int mini = -1;
		int pfx = 0;  // 0 -> 1
		for (int i = 0; i < rep*l; ++i) {
			pfx = m[pfx][s[i]];
			if (pfx == 1) {  // i-> 1
				mini = i + 1;
				break;
			}
		}
		if (mini == -1) {
			cout << "Case #" << test << ": NO" << endl;
			continue;
		}

		int mink = -1;
		int sfx = 0;  // 0 -> 1
		for (int k = rep*l - 1; k >= 0; --k) {
			sfx = m[s[k]][sfx];
			if (sfx == 3) {  // 3 -> k
				mink = rep*l - k;
				break;
			}
		}
		if (mink == -1) {
			cout << "Case #" << test << ": NO" << endl;
			continue;
		}

		if (mini + mink >= x*l) {
			cout << "Case #" << test << ": NO" << endl;
		} else {
			cout << "Case #" << test << ": YES" << endl;
		}
	}
}
