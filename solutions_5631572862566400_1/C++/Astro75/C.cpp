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

int a[1000 + 10];
int len[1000 + 10];
int st[1000 + 10];

int best = 0;

int loop(int s) {
	st[s] = 1;
	int n = a[s];
	if (a[n] == s) {
		st[n] = 10;
		st[s] = 10;
		len[n] = 2;
		len[s] = 2;
		return len[s];
	} else if (st[n] == 0) {
		int ll = loop(n);
		if (st[n] == 10) {
			st[s] = 10;
		} else if (st[n] == 20) {
			if (st[s] == 21) {
				best = max(best, ll + 1);
			}
			st[s] = 20;
		}
		len[s] = ll + 1;
		return len[s];
	} else if (st[n] == 1) {
		// real loop
		st[s] = 20;
		st[n] = 21;
		len[s] = 1;
		return len[s];
	}
	st[s] = st[n];
	len[s] = len[n] + 1;
	return len[s];
}



int clear(int s) {
	if (st[s] == -1) return 0;
	st[s] = -1;
	if (a[a[s]] == s) {
		if (st[a[s]] == -1) {
			return 1;
		} else {
			st[a[s]] = 9;
			return 2;
		}
	}
	return clear(a[s]); 
}

int solve() {
	int n;
	cin >> n;
	REP(i, n) {
		cin >> a[i];
		a[i]--;
		len[i] = -1;
		st[i] = 0;
	}
	best = 0;
	REP(i, n) if (st[i] == 0) loop(i);
	int tot = 0;
	bool work = true;
	// cout << endl;
	// REP(i, n) cout << st[i] << ' '; cout << endl;
	// REP(i, n) cout << len[i] << ' '; cout << endl;
	while (work) {
		work = false;
		int ind = 0;
		REP(i, n) {
			if (st[i] == 10) {
				if (!work) {
					work = true;
					ind = i;
				} else {
					if (len[ind] < len[i]) {
						ind = i;
					}
				}
			}
		}
		if (work) {
			int c = clear(ind);
			if (c != 0) {
				// cout << ind << ';' << c << endl;
				tot += len[ind];
				if (c == 1) tot -= 2;
			}
		}
	}
	// cout << best << ' ' << tot << endl;
	return max(tot, best);
}

int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ": ";
		cout << solve();
		cout << endl;
	}
}