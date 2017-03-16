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

int n;

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

void solve() {
	string sa, sb;
	cin >> sa >> sb;
	n = sa.size();
	int best = 10000000;
	int ra, rb;
	int ma = 1;
	REP(i,n) ma *= 10;
	REP(a,ma) REP(b,ma) {
		int nres = abs(a-b);
		if (nres >= best) continue;
		if (test(a,sa) && test(b,sb)) {
			best = nres;
			ra = a;
			rb = b;
		}
	}
	pr(ra, n); cout << ' '; pr(rb, n);
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