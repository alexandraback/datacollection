#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;


int TC;
void solve() {
	int N;
	cin >> N;
	vector<vector<int>> vs;
	rep(i, 2*N-1) {
		vector<int> v(N);
		rep(i, N) cin >> v[i];
		vs.emplace_back(v);
	}

	rep(s, 1<<(2*N-1)) {
		if (__builtin_popcount(s) != N) continue;
		vector<vector<int>> A(N, vector<int>(N, -1));
		vector<vector<int>> ws, rs;
		rep(i, 2*N-1) {
			if (!(s>>i&1)) {
				rs.push_back(vs[i]);
				continue;
			}
			ws.push_back(vs[i]);
		}
		sort(all(ws));
		rep(i, sz(ws)) {
			rep(j, N) {
				A[i][j] = ws[i][j];
			}
		}
		bool ok = true;
		rep(j, N) rep(i, N-1) if (!(A[i][j] < A[i+1][j])) {
			ok = false;
			break;
		}
		if (!ok) continue;
		rep(i, N) rep(j, N-1) if (!(A[i][j] < A[i][j+1])) {
			ok = false;
			break;
		}
		if (!ok) continue;
		int notfound = -1;
		rep(j, N) {
			bool found = false;
			for(auto it = rs.begin(); it != rs.end(); it++) {
				const auto &v = *it;
				bool valid =  true;
				rep(i, N) if (v[i] != A[i][j]) {
					valid = false;
					break;
				}
				if (valid) {
					rs.erase(it);
					found = true;
					break;
				}
			}
			if (!found) {
				if (notfound != -1) {
					ok = false;
					break;
				}
				notfound = j;
			}
		}
		if (!ok) continue;

		rep(i, N) {
			if (i) cout << ' ';
			cout << A[i][notfound];
		}
		cout << endl;
		break;
	}
}
int main() {
	int T; cin >> T;
	for(int TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

