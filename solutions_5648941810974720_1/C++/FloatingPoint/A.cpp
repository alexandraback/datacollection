#include <bits/stdc++.h>

using namespace std;

vector<string> results;
int T;

string solve(string& s) {
	map<char, int> chars;
	map<int, int> nums;
	for (int I = 0; I < s.size(); ++I) chars[s[I]]++;
	nums[0] = chars['Z'];
	nums[2] = chars['W'];
	nums[4] = chars['U'];
	nums[6] = chars['X'];
	nums[8] = chars['G'];
	nums[5] = chars['F'] - nums[4];
	nums[1] = chars['O'] - nums[0] - nums[2] - nums[4];
	nums[3] = chars['H'] - nums[8];
	nums[7] = chars['V'] - nums[5];
	nums[9] = chars['I'] - nums[5] - nums[6] - nums[8];
	string t;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < nums[i]; ++j)
			t += ('0' + i);
	return t;
}

int main() {
#ifndef LOCAL
	freopen("A.txt", "r", stdin);
	freopen("A.out.txt", "w", stdout);
#endif
	cin >> T;
	results.resize(T);
	for (int i = 0; i < T; ++i) {
		string s;
		cin >> s;
		results[i] = solve(s);
	}
	
	for (int i = 0; i < T - 1; ++i) cout << "Case #" << i + 1 << ": " << results[i] << endl;
	cout << "Case #" << T << ": " << results[T-1];
}