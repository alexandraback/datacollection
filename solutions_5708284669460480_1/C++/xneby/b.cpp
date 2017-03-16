#include <bits/stdc++.h>
using namespace std;

struct Solver {
	string k, t;
	int n;
	int l;

	vector<int> P;

	vector<vector<bool>> ok;
	vector<vector<int>> mm;

	Solver(string k, string t, int l): k(k), t(t), n(t.length()), l(l), mm(l+1, vector<int>(n+1)), ok(l+1, vector<bool>(n+1)) {}

	void compute_P() {
		P.push_back(0);
		P.push_back(0);
		int k = 0;
		for(int i = 1; i < n; i++) {
			while(k > 0 && t[i] != t[k]) k = P[k];
			if(t[i] == t[k]) k++;
			P.push_back(k);
		}
	}

	map<pair<int, char>, int> mem;

	int next(int m, char c, bool& match) {
		auto it = mem.find({m, c});
		int om = m;
		int res;
		if(it != mem.end()) res = it->second;
		else {
			while(m > 0 && t[m] != c) {
				m = P[m];
			}
			if(t[m] == c) m++;
			res = m;
		}
		mem[{om, c}] = res;

		if(res == n) {
			match = true;
			res = P[res];
		} else match = false;

		return res;
	}

	double solve() {
		compute_P();

		ok[0][0] = true;
		double k1 = 1. / k.size();

		for(int i = 0; i < l; i++) {
			for(int m = 0; m < n; m++) {
				if(!ok[i][m]) continue;
				for(char c : k) {
					bool match;
					int next_m = next(m, c, match);
					ok[i+1][next_m] = true;
					mm[i+1][next_m] = max(mm[i+1][next_m], mm[i][m] + match);
				}
			}
		}
		int mmm = 0;
		double res = 1;

		map<char, int> Z;
		for(char x : k) Z[x] ++;
		int kk = k.length();
		for(char x : t) res *= 1. * Z[x] / kk;
		res *= l - n + 1;

		for(int i=0; i<n; i++) {
			if(!ok[l][i]) continue;
			mmm = max(mmm, mm[l][i]);
		}

		cerr << mmm << " " << res << endl;
		return mmm - res;
	}
};

double test() {
	int k, l, s;
	string A, B;
	cin >> k >> l >> s;
	cin >> A >> B;

	Solver S(A, B, s);

	return S.solve();
}

int main() {
	cerr << boolalpha;
	int t;
	cin >> t;
	cout << fixed << setprecision(7);
	for(int i=1; i<=t; i++) {
		double res = test();
		cout << "Case #" << i << ": " << res << endl;
	}
}
