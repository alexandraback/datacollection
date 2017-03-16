#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string L[] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" 
};

int cnt[500];

string solve (vector <int> &nums, string s) {
		for (int i = 0; i < s.size(); ++i) {
			cnt[s[i]]++;
		}
		string ans;
		for (int l = 0; l < 10; ++l) {
			int i = nums[l];
			map <char, int> m;
			for (int j = 0; j < L[i].size(); ++j) m[L[i][j]]++;
			int good = true;
			while (good) {
				for (auto x : m) {
					if (cnt[x.first] < x.second) good = false;
				}
				if (good) {
					ans += (char)('0'  + i);
					for (auto x : m) {
						cnt[x.first] -= x.second;
					}
				}
			}
		}
		sort (ans.begin(), ans.end());
		return ans;
}

int main (void) {
	int t;
	cin >> t;
	for (int c = 1; c <= t; ++c) {
		memset (cnt, 0, sizeof cnt);
		string s;
		cin >> s;
		printf ("Case #%d: ", c);
		vector <int> v = { 0, 2, 6, 7, 5, 4, 1, 9, 8, 3 };
		string ans = solve (v, s);
		printf ("%s\n", ans.c_str());
	}
	return 0;
}
