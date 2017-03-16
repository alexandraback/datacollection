#include <bits/stdc++.h>
#define rep(x, to) for (int x = 0; x < (to); x++)
#define REP(x, a, to) for (int x = (a); x < (to); x++)
#define foreach(itr, x) for (typeof((x).begin()) itr = (x).begin(); itr != (x).end(); itr++)
#define EPS (1e-14)
#define _PA(x,N) rep(i,N){cout<<x[i]<<" ";}cout<<endl;
#define _PA2(x,H,W) rep(i,(H)){rep(j,(W)){cout<<x[i][j]<<" ";}cout<<endl;}

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef complex<double> Complex;
typedef vector< vector<int> > Mat;

int T;
string S;
string ans;

map<char, int> freq;
/*

	 ZERO
	 EIGHT
	 THREE
	 FOUR
	 TWO
	 SIX
	 FIVE
	 ONE
	 SEVEN
	 /NINE


*/

string W[10] = {
	 "ZERO",
	 "EIGHT",
	 "THREE",
	 "FOUR",
	 "TWO",
	 "SIX",
	 "FIVE",
	 "ONE",
	 "SEVEN",
	 "NINE"
};

int rW[10] = {
	0,
	8,
	3,
	4,
	2,
	6,
	5,
	1,
	7,
	9
};


bool exist(map<char, int> cp_freq, string &w) {
	rep(i, w.size()) {
		cp_freq[w[i]] -= 1;
		if (cp_freq[w[i]] < 0) return false;
	}
	return true;
}

void update(string &w) {
	rep(i, w.size()) {
		freq[w[i]] -= 1;
	}
}

void debug() {
	foreach(itr, freq) {
		cout << itr->first << " " << itr->second << endl;
	}
}


string solve() {
	string res = "";
	freq.clear();

	rep(i, S.size()) {
		freq[S[i]] += 1;
	}

	//debug();

	rep(i, 10) {
		while (exist(freq, W[i])) {
			update(W[i]);
			res += (char)('0' + rW[i]);
		}
	}
	sort(res.begin(), res.end());

	return res;
}

int main() {
	cin >> T;
	rep(i, T) {
		cin >> S;
		ans = solve();
		printf("Case #%d: %s\n", i + 1, ans.c_str());
	}
	return 0;
}


