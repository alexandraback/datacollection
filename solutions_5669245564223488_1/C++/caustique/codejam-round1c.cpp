#pragma comment(linker,"/stack:256000000")

#include <cmath> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <cstdio> 
#include <cfloat>
#include <cassert>
#include <ctime>

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

const int MOD = (int)1e9 + 7;

long long F[110];

string getsegm(string s) {
	s += ".";
	string res;
	char p = s[0];
	REP(i, sz(s)) {
		if (s[i] != p) {
			res += p;
			p = s[i];
		}
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector <string> s(n);
	REP(i, n) cin >> s[i];
	vector <int> lf(26), rg(26), ins(26), wh(26);
	vector <int> ilf(26), irg(26);
	REP(j, n) {
		string v = getsegm(s[j]);
		vector <int> cnt(26);
		REP(i, sz(v)) cnt[v[i] - 'a']++;
		REP(i, 26) {
			if (cnt[i] > 1) {
				cout << 0 << endl;
				return;
			}
		}
		if (sz(v) == 1) {
			wh[v[0] - 'a']++;
		} else {
			lf[v[0] - 'a']++;
			ilf[v[0] - 'a'] = v[sz(v) - 1] - 'a';
			rg[v[sz(v) - 1] - 'a']++;
			irg[v[sz(v) - 1] - 'a'] = v[0] - 'a';
			for (int i = 1; i < sz(v) - 1; i++) {
				ins[v[i] - 'a']++;
			}
		}
	}
	vector <bool> used(26);
	REP(i, 26) {
		if (lf[i] > 1 || rg[i] > 1 || ins[i] > 1) {
			cout << 0 << endl;
			return;
		}
		if (ins[i] == 1) {
			if (lf[i] > 0 || rg[i] > 0 || wh[i] > 0) {
				cout << 0 << endl;
				return;
			} else {
				used[i] = 1;
			}
		}
		if (lf[i] == 0 && rg[i] == 0 && ins[i] == 0 && wh[i] == 0) {
			used[i] = 1;
		}
	}
	long long res = 1;
	int blocks = 0;
	REP(i, sz(used)) {
		if (used[i]) continue;
		if (wh[i] > 0 && lf[i] == 0 && rg[i] == 0) {
			blocks++;
			res *= F[wh[i]];
			res %= MOD;
			used[i] = 1;
		}
	}
	for(;;) {
		bool fin = 1;
		REP(i, sz(used)) {
			if (!used[i]) {
				fin = 0;
				break;
			}
		}
		if (fin) break;
		int L = -1;
		REP(i, sz(used)) {
			if (used[i]) continue;
			if (lf[i] > 0 && rg[i] == 0) {
				L = i;
				break;
			}
		}
		if (L == -1) {
			cout << 0 << endl;
			return;
		}
		int id = L;
		for(;;) {
			if (used[id]) {
				cout << 0 << endl;
				return;
			}
			used[id] = 1;
			res *= F[wh[id]];
			res %= MOD;
			if (rg[id] > 0 && lf[id] == 0) {
				break;
			}
			id = ilf[id];
		}
		++blocks;
	}
	res *= F[blocks];
	res %= MOD;
	cout << res << endl;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long start = clock();
#endif
	F[0] = 1;
	for (int i = 1; i < 110; i++) {
		F[i] = (F[i - 1] * i) % MOD;
	}
	int T;
	cin >> T;
	for (int tst = 1; tst <= T; tst++) {
		cerr << tst << endl;
		cout << "Case #" << tst << ": ";
		solve();
	}
	return 0;
}