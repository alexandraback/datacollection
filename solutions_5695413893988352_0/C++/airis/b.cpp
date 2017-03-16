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
string C, J;

vector<int> VC, VJ;

void dfs(string X, int p, int cur, vector<int> &vec) {
	if (p == X.size()) {
		vec.push_back(cur);
		return;
	}
	int v = 0;
	if (X[p] == '?') {
		for (int i = 0; i < 10; i++) {
			dfs(X, p + 1, 10 * cur + i, vec);
		}
	} else {
		v = X[p] - '0';
		dfs(X, p + 1, 10 * cur + v, vec);
	}
}


void debug(vector<int> &vec) {
	rep(i, vec.size()) {
		cout << vec[i] << endl;
	}
}

void solve(int t) {
	VC.clear();
	VJ.clear();
	dfs(C, 0, 0, VC);
	dfs(J, 0, 0, VJ);

	int ans_diff = 1e+9 + 7;
	int ans_c = 0, ans_j = 0;
	rep(i, VC.size()) {
		rep(j, VJ.size()) {
			int diff = abs(VC[i] - VJ[j]);
			if (diff < ans_diff) {
				ans_diff = diff;
				ans_c = VC[i];
				ans_j = VJ[j];
			} else if (diff == ans_diff) {
				if (VC[i] < ans_c) {
					ans_c = VC[i];
				} else if (VC[i] == ans_c) {
					if (VJ[j] < ans_j) {
						ans_j = VJ[j];
					}
				}
			}
		}
	}
#if 0
	debug(VC);
	cout << "---" << endl;
	debug(VJ);
#endif
	if (C.size() == 3) {
		printf("Case #%d: %03d %03d\n", t + 1, ans_c, ans_j);
	} else if (C.size() == 2) {
		printf("Case #%d: %02d %02d\n", t + 1, ans_c, ans_j);
	} else {
		printf("Case #%d: %d %d\n", t + 1, ans_c, ans_j);
	}
}

int main() {
	cin >> T;
	rep(i, T) {
		cin >> C >> J;
		solve(i);
	}
	return 0;
}


