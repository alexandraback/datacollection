#include <bits/stdc++.h>
using namespace std;

string numbers[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
		"SEVEN", "EIGHT", "NINE" };
char unique_char[] = {'Z', 'W', 'U', 'X', 'G', 'R', 'S', 'V', 'O', 'I'};
int unique_idx[] = {0, 2, 4, 6, 8, 3, 7, 5, 1, 9};

void __main() {
	string str;
	cin >> str;
	vector<int> char_vec(256, 0);
	for (char c : str) {
		char_vec[c]++;
	}
	vector<int> ans;
	for (int i = 0; i < 10; ++i) {
		while (char_vec[(int)unique_char[i]] > 0) {
			for (char c : numbers[unique_idx[i]]) {
				char_vec[(int)c]--;
			}
			ans.push_back(unique_idx[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i;
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase) {
		cout << "Case #" << testcase << ": ";
		__main();
	}
	return 0;
}
