#include <bits/stdc++.h>
using namespace std;

string ss[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

void solve() {
	string s;
	cin >> s;

	map<char, int> mp;
	for (char c : s) mp[c]++;

	vector<int> num(10);
	while (mp['Z'] > 0) {
		num[0]++;
		for (char c : ss[0]) mp[c]--;
	}
	while (mp['W'] > 0) {
		num[2]++;
		for (char c : ss[2]) mp[c]--;
	}
	while (mp['U'] > 0) {
		num[4]++;
		for (char c : ss[4]) mp[c]--;
	}
	while (mp['G'] > 0) {
		num[8]++;
		for (char c : ss[8]) mp[c]--;
	}
	while (mp['R'] > 0) {
		num[3]++;
		for (char c : ss[3]) mp[c]--;
	}
	while (mp['O'] > 0) {
		num[1]++;
		for (char c : ss[1]) mp[c]--;
	}
	while (mp['F'] > 0) {
		num[5]++;
		for (char c : ss[5]) mp[c]--;
	}
	while (mp['X'] > 0) {
		num[6]++;
		for (char c : ss[6]) mp[c]--;
	}
	while (mp['V'] > 0) {
		num[7]++;
		for (char c : ss[7]) mp[c]--;
	}
	while (mp['E'] > 0) {
		num[9]++;
		for (char c : ss[9]) mp[c]--;
	}
	string ans;
	for (int i = 0; i < 10; i++) ans += string(num[i], '0' + i);
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
