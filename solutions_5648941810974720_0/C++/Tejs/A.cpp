#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

void solve(string s) {
	int counter[26];
	for(int i = 0;i < 26; ++i) counter[i] = 0;
	int n(s.length());
	for(int i = 0;i < n; ++i) {
		++counter[s[i]-'A'];
	}
	string nums[] = {"ZERO", "TWO", "FOUR", "EIGHT", "ONE", "FIVE", "THREE", "SEVEN", "SIX", "NINE"};
	int numbers[] = {0,2,4,8,1,5,3,7,6,9};
	char unique[] = {'Z', 'W', 'U', 'G', 'O', 'F', 'T', 'V', 'X', 'I'};
	int ans[10];
	for(int i = 0;i < 10; ++i) ans[i] = 0;
	for(int i = 0;i < 10; ++i) {
		int c = counter[unique[i]-'A'];
		string s = nums[i];
		int m(s.length());
		for(int j = 0;j < m;++j) {
			counter[nums[i][j]-'A'] -= c;
		}
		ans[numbers[i]] = c;
	}
	for(int i = 0;i < 10; ++i) {
		for(int j = 0;j < ans[i]; ++j) {
			cout << i;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for(int t = 1;t <= T; ++t) {
		string s;
		cin >> s;
		cout << "Case #" << t << ": ";
		solve(s);
		cout << endl;
	}
	return 0;
}
