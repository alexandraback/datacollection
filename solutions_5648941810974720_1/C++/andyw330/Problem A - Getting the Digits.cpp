#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

string num_str[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int p[] = {0, 6, 8, 4, 7, 5, 9, 3, 2, 1};

void print(int* idx) {
	for (int i = 0; i < 26; ++i) {
		if (idx[i]) {
			cout << char(i + 'A') << ":" << idx[i] << " ";
		}
	}
	cout << endl;
}

int main() {
	int t, ct, tc = 0;
	string s, ans;
	cin >> t;
	while (t--) {
		int idx[27] = {};
		cin >> s;
		for (int i = 0; i < s.length(); ++i) {
			idx[s[i] - 'A']++;
		}

		ans = "";
		for (int i = 0; i < 10; ++i) {
			int x = p[i];
			ct = 1e9;
			for (int j = 0; j < num_str[x].length(); ++j) {
				if ((x == 3 && num_str[x][j] == 'E') || (x == 7 && num_str[x][j] == 'E') || (x == 9 && num_str[x][j] == 'N'))
					ct = min(ct, idx[num_str[x][j] - 'A'] / 2);
				else
					ct = min(ct, idx[num_str[x][j] - 'A']);
			}
			for (int j = 0; j < num_str[x].length(); ++j) {
				idx[num_str[x][j] - 'A'] -= ct;
			}
			//cout << endl;
			//print(idx);
			for (int k = 0; k < ct; ++k) {
				ans += char(x + '0');
			}
		}
		cout << "Case #" << ++tc << ": ";
		sort(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}