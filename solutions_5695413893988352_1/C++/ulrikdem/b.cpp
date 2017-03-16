#include <bits/stdc++.h>
using namespace std;

long long pick(string& c, string& j, long long cnum = 0, long long jnum = 0, int i = 0) {
	while(i < c.size()) {
		if(c[i] == '?' && j[i] == '?') {
			if(cnum < jnum) {
				c[i] = '9';
				j[i] = '0';
			} else if(cnum > jnum) {
				c[i] = '0';
				j[i] = '9';
			} else {
				string bestc = c, bestj = j;
				bestc[i] = bestj[i] = '0';
				long long best = pick(bestc, bestj, cnum * 10, jnum * 10, i + 1);
				string tempc = c, tempj = j;
				tempc[i] = '0';
				tempj[i] = '1';
				long long option = pick(tempc, tempj, cnum * 10, jnum * 10 + 1, i + 1);
				if(option < best) {
					bestc = tempc;
					bestj = tempj;
					best = option;
				}
				tempc = c;
				tempj = j;
				tempc[i] = '1';
				tempj[i] = '0';
				option = pick(tempc, tempj, cnum * 10 + 1, jnum * 10, i + 1);
				if(option < best) {
					bestc = tempc;
					bestj = tempj;
					best = option;
				}
				c = bestc;
				j = bestj;
				return best;
			}
		} else if(c[i] == '?') {
			if(cnum < jnum) {
				c[i] = '9';
			} else if(cnum > jnum) {
				c[i] = '0';
			} else {
				string bestc = c, bestj = j;
				bestc[i] = j[i];
				long long best = pick(bestc, bestj, cnum * 10 + bestc[i] - '0', jnum * 10 + bestj[i] - '0', i + 1);
				if(j[i] != '0') {
					string tempc = c, tempj = j;
					tempc[i] = j[i] - 1;
					long long option = pick(tempc, tempj, cnum * 10 + tempc[i] - '0', jnum * 10 + tempj[i] - '0', i + 1);
					if(option <= best) {
						bestc = tempc;
						bestj = tempj;
						best = option;
					}
				}
				if(j[i] != '9') {
					string tempc = c, tempj = j;
					tempc[i] = j[i] + 1;
					long long option = pick(tempc, tempj, cnum * 10 + tempc[i] - '0', jnum * 10 + tempj[i] - '0', i + 1);
					if(option < best) {
						bestc = tempc;
						bestj = tempj;
						best = option;
					}
				}
				c = bestc;
				j = bestj;
				return best;
			}
		} else if(j[i] == '?') {
			if(cnum < jnum) {
				j[i] = '0';
			} else if(cnum > jnum) {
				j[i] = '9';
			} else {
				string bestc = c, bestj = j;
				bestj[i] = c[i];
				long long best = pick(bestc, bestj, cnum * 10 + bestc[i] - '0', jnum * 10 + bestj[i] - '0', i + 1);
				if(c[i] != '0') {
					string tempc = c, tempj = j;
					tempj[i] = c[i] - 1;
					long long option = pick(tempc, tempj, cnum * 10 + tempc[i] - '0', jnum * 10 + tempj[i] - '0', i + 1);
					if(option <= best) {
						bestc = tempc;
						bestj = tempj;
						best = option;
					}
				}
				if(c[i] != '9') {
					string tempc = c, tempj = j;
					tempj[i] = c[i] + 1;
					long long option = pick(tempc, tempj, cnum * 10 + tempc[i] - '0', jnum * 10 + tempj[i] - '0', i + 1);
					if(option < best) {
						bestc = tempc;
						bestj = tempj;
						best = option;
					}
				}
				c = bestc;
				j = bestj;
				return best;
			}
		}
		cnum = cnum * 10 + c[i] - '0';
		jnum = jnum * 10 + j[i] - '0';
		++i;
	}
	return abs(cnum - jnum);
}

void solve() {
	string c, j;
	cin >> c >> j;
	pick(c, j);
	cout << ' ' << c << ' ' << j << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; ++i) {
		cout << "Case #" << i << ':';
		solve();
	}
	return 0;
}
