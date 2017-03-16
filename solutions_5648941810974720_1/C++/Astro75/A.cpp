#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char lets[] = {'Z','W','X','G','H','R','F','I','O','S'};
int   idx[] = {0,2,6,8,3,4,5,9,1,7};

int cnt[26];
int res[10];

void solve() {
	string s;
	cin >> s;
	REP(i,26) cnt[i] = 0;
	REP(i,10) res[i] = 0;
	for (char c : s) cnt[c-'A']++;
	// cout << cnt['G'-'A'] << endl;
	REP(i,10) {
		int sub = cnt[lets[i]-'A'];
		// cout << sub << endl;
		res[idx[i]] = sub;
		for(char c : nums[idx[i]]) {
			cnt[c-'A'] -= sub;
		}
	}
	REP(i,10) {
		REP(j,res[i]) {
			cout << i;
		}
	}
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ": ";
		solve();
		cout << endl;
	}
}