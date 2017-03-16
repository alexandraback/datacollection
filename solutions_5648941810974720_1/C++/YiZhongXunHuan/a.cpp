#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int cnt[256];
int cnt_d[10];

void solve(string s) {
	for (int i = 0; i < 256; i++)
		cnt[i] = 0;
	for (int i = 0; i < s.size(); i++)
		cnt[s[i]]++;
	for (int i = 0; i < 10; i++)
		cnt_d[i] = 0;
	cnt_d[0] = cnt['Z'];
	cnt['E'] -= cnt['Z'];
	cnt['R'] -= cnt['Z'];
	cnt['O'] -= cnt['Z'];
	cnt['Z'] = 0;
	cnt_d[2] = cnt['W'];
	cnt['T'] -= cnt['W'];
	cnt['O'] -= cnt['W'];
	cnt['W'] = 0;
	cnt_d[4] = cnt['U'];
	cnt['F'] -= cnt['U'];
	cnt['O'] -= cnt['U'];
	cnt['R'] -= cnt['U'];
	cnt['U'] = 0;
	cnt_d[8] = cnt['G'];
	cnt['E'] -= cnt['G'];
	cnt['I'] -= cnt['G'];
	cnt['H'] -= cnt['G'];
	cnt['T'] -= cnt['G'];
	cnt['G'] = 0;
	cnt_d[3] = cnt['T'];
	cnt['H'] -= cnt['T'];
	cnt['R'] -= cnt['T'];
	cnt['E'] -= cnt['T'];
	cnt['E'] -= cnt['T'];
	cnt['T'] = 0;
	cnt_d[5] = cnt['F'];
	cnt['I'] -= cnt['F'];
	cnt['V'] -= cnt['F'];
	cnt['E'] -= cnt['F'];
	cnt['F'] = 0;
	cnt_d[1] = cnt['O'];
	cnt['N'] -= cnt['O'];
	cnt['E'] -= cnt['O'];
	cnt['O'] = 0;
	cnt_d[6] = cnt['X'];
	cnt['S'] -= cnt['X'];
	cnt['I'] -= cnt['X'];
	cnt['X'] = 0;
	cnt_d[7] = cnt['S'];
	cnt['E'] -= cnt['S'];
	cnt['V'] -= cnt['S'];
	cnt['E'] -= cnt['S'];
	cnt['N'] -= cnt['S'];
	cnt['S'] = 0;
	cnt_d[9] = cnt['I'];
	cnt['N'] -= cnt['I'];
	cnt['N'] -= cnt['I'];
	cnt['E'] -= cnt['I'];
	cnt['I'] = 0;
	for (int i = 0; i < 10; i++)
		while (cnt_d[i]--)
			cout << (char)('0' + i);
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		string s;
		cin >> s;
		solve(s);
	}
	return 0;
}
