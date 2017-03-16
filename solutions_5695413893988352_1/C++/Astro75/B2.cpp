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

typedef long long ll;

int n;
string sa, sb;

bool test(int num, string s) {
	num *= 10;
	REP(i,n) {
		num /= 10;
		if (s[n-1-i] == '?') continue;
		if (num % 10 != s[n-1-i] - '0') return false;
	}
	return true;
}

void pr(int num, int len) {
	if (len > 1) pr(num / 10, len-1);
	cout << num % 10;
}

string ba, bb;
bool done = false;

bool nexteq(int i) {
	i++;
	if (i == n) return true;
	if (sa[i] == '?') return true;
	if (sb[i] == '?') return true;
	return sa[i] == sb[i];
}

void rec(int i, int side) {
	if (i == n) {
		// cout << "t " << sa << ' ' << sb << endl;
		if (done) {
			ll dbest = abs(stoll(ba) - stoll(bb));
			ll dcur = abs(stoll(sa) - stoll(sb));
			if (dcur > dbest) return;
			if (dcur == dbest) {
				if (stoll(sa) > stoll(ba)) return;
				if (stoll(sa) == stoll(ba)) {
					if (stoll(sb) > stoll(bb)) return;
				}
			}
		}
		done = true;
		ba = sa;
		bb = sb;
		return;
	}
	char pa = sa[i];
	char pb = sb[i];
	if (side == 0) {
		int eq = false;
		if (sa[i] == '?' && sb[i] == '?') {
			sa[i] = '0';
			sb[i] = '0';
			if (!eq) {
				rec(i+1, 0);
				sa[i] = '1';
				sb[i] = '0';
				rec(i+1, 1);
				sa[i] = '0';
				sb[i] = '1';
				rec(i+1, -1);
				sa[i] = pa; sb[i] = pb;
				return;
			}
		} else if (sa[i] == '?') {
			sa[i] = sb[i];
			if (!eq) {
				rec(i+1, 0);
				sa[i]++;
				if (sa[i] <= '9') rec(i+1, 1);
				sa[i] -= 2;
				if (sa[i] >= '0') rec(i+1, -1);
				sa[i] = pa; sb[i] = pb;
				return;
			}
		} else if (sb[i] == '?') {
			sb[i] = sa[i];
			if (!eq) {
				rec(i+1, 0);
				sb[i]++;
				if (sb[i] <= '9') rec(i+1, -1);
				sb[i] -= 2;
				if (sb[i] >= '0') rec(i+1, 1);
				sa[i] = pa; sb[i] = pb;
				return;
			}
		} else if (sa[i] == sb[i]) {
			//good
		} else {
			if (sa[i] < sb[i]) {
				side = -1;
			} else {
				side = 1;
			}
		}
	} else if (side == -1) {
		if (sa[i] == '?') sa[i] = '9';
		if (sb[i] == '?') sb[i] = '0';
	} else if (side == 1) {
		if (sa[i] == '?') sa[i] = '0';
		if (sb[i] == '?') sb[i] = '9';
	}
	rec(i+1, side);
	sa[i] = pa; sb[i] = pb;
}

void solve() {
	done = false;
	cin >> sa >> sb;
	n = sa.size();
	rec(0,0);
	cout << ba << ' ' << bb;
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