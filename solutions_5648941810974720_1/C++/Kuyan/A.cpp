#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	freopen("A-large.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		string s;
		cin >> s;
		int n = int(s.size());
		vector<int> cnt(26);
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'A']++;
		}
		vector<int> ans;
		while (cnt['Z' - 'A'] > 0) {
			ans.push_back(0);
			cnt['Z' - 'A']--;
			cnt['E' - 'A']--;
			cnt['R' - 'A']--;
			cnt['O' - 'A']--;
		}
		while (cnt['W' - 'A'] > 0) {
			ans.push_back(2);
			cnt['T' - 'A']--;
			cnt['W' - 'A']--;
			cnt['O' - 'A']--;
		}
		while (cnt['U' - 'A'] > 0) {
			ans.push_back(4);
			cnt['F' - 'A']--;
			cnt['O' - 'A']--;
			cnt['U' - 'A']--;
			cnt['R' - 'A']--;
		}
		while (cnt['X' - 'A'] > 0) {
			ans.push_back(6);
			cnt['S' - 'A']--;
			cnt['I' - 'A']--;
			cnt['X' - 'A']--;
		}
		while (cnt['G' - 'A'] > 0) {
			ans.push_back(8);
			cnt['E' - 'A']--;
			cnt['I' - 'A']--;
			cnt['G' - 'A']--;
			cnt['H' - 'A']--;
			cnt['T' - 'A']--;
		}

		while (cnt['O' - 'A'] > 0) {
			ans.push_back(1);
			cnt['O' - 'A']--;
			cnt['N' - 'A']--;
			cnt['E' - 'A']--;
		}
		while (cnt['T' - 'A'] > 0) {
			ans.push_back(3);
			cnt['T' - 'A']--;
			cnt['H' - 'A']--;
			cnt['R' - 'A']--;
			cnt['E' - 'A']--;
			cnt['E' - 'A']--;
		}
		while (cnt['F' - 'A'] > 0) {
			ans.push_back(5);
			cnt['F' - 'A']--;
			cnt['I' - 'A']--;
			cnt['V' - 'A']--;
			cnt['E' - 'A']--;
		}
		while (cnt['S' - 'A'] > 0) {
			ans.push_back(7);
			cnt['S' - 'A']--;
			cnt['E' - 'A']--;
			cnt['V' - 'A']--;
			cnt['E' - 'A']--;
			cnt['N' - 'A']--;
		}
		while (cnt['N' - 'A'] > 0) {
			ans.push_back(9);
			cnt['N' - 'A']--;
			cnt['I' - 'A']--;
			cnt['N' - 'A']--;
			cnt['E' - 'A']--;
		}
		sort(ans.begin(), ans.end());
		cout << "Case #" << it + 1 << ": ";
		for (int i = 0; i < int(ans.size()); i++) {
			cout << ans[i];
		}
		cout << endl;
	}
    return 0;
}

