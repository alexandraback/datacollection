#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

int T, id;
string s;
int cnt[26];

void solve() {
	id++;
	cout << "Case #" << id << ": ";
	cin >> s;

	for (int i = 0; i < 26; ++i)
		cnt[i] = 0;

	for (int i = 0; i < s.size(); ++i) {
		cnt[s[i] - 'A']++;
	}

	vector < int > ans;

 	while (cnt['Z' - 'A'] > 0) {
		cnt['Z' - 'A']--;
		cnt['E' - 'A']--;
		cnt['R' - 'A']--;
		cnt['O' - 'A']--;
		ans.push_back(0);
 	}

 	while (cnt['X' - 'A'] > 0) {
		cnt['S' - 'A']--;
		cnt['I' - 'A']--;
		cnt['X' - 'A']--;
		ans.push_back(6);
 	}

 	while (cnt['U' - 'A'] > 0) {
		cnt['F' - 'A']--;
		cnt['O' - 'A']--;
		cnt['U' - 'A']--;
		cnt['R' - 'A']--;
		ans.push_back(4);
 	}

 	while (cnt['F' - 'A'] > 0) {
		cnt['F' - 'A']--;
		cnt['I' - 'A']--;
		cnt['V' - 'A']--;
		cnt['E' - 'A']--;
		ans.push_back(5);
 	}

 	while (cnt['V' - 'A'] > 0) {
		cnt['S' - 'A']--;
		cnt['E' - 'A']--;
		cnt['V' - 'A']--;
		cnt['E' - 'A']--;
		cnt['N' - 'A']--;
		ans.push_back(7);
 	}

 	while (cnt['G' - 'A'] > 0) {
		cnt['E' - 'A']--;
		cnt['I' - 'A']--;
		cnt['G' - 'A']--;
		cnt['H' - 'A']--;
		cnt['T' - 'A']--;
		ans.push_back(8);
 	}
	
 	while (cnt['V' - 'A'] > 0) {
		cnt['S' - 'A']--;
		cnt['E' - 'A']--;
		cnt['V' - 'A']--;
		cnt['E' - 'A']--;
		cnt['N' - 'A']--;
		ans.push_back(7);
 	}

 	while (cnt['W' - 'A'] > 0) {
		cnt['T' - 'A']--;
		cnt['W' - 'A']--;
		cnt['O' - 'A']--;
		ans.push_back(2);
 	}

 	while (cnt['T' - 'A'] > 0) {
		cnt['T' - 'A']--;
		cnt['H' - 'A']--;
		cnt['R' - 'A']--;
		cnt['E' - 'A']--;
		cnt['E' - 'A']--;
		ans.push_back(3);
 	}
	

 	while (cnt['O' - 'A'] > 0) {
		cnt['O' - 'A']--;
		cnt['N' - 'A']--;
		cnt['E' - 'A']--;
		ans.push_back(1);
 	}

 	while (cnt['I' - 'A'] > 0) {
		cnt['N' - 'A']--;
		cnt['I' - 'A']--;
		cnt['N' - 'A']--;
		cnt['E' - 'A']--;
		ans.push_back(9);
 	}

 	sort(ans.begin(), ans.end());
	 	
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i];
	cout << endl;
	
}

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
                                

