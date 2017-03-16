#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)

typedef unsigned long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

ll solve() {
	int e, r;
	int n;

	cin >> e >> r >> n;

	vvi best(n+1, vi(e+r+1));
	vi v(n);
	REP(i,n)
		cin >> v[i];

	FOR(row,1,n+1) {
		//cout << v[row-1] << ":\t";
		FOR(i,r, e+1) {
			int sol = 0;
			// for every possible previous amount of energy
			FOR(j,max(r, i-r), e+1) {
				int taken = (j + r) - i;
				sol = max(sol, best[row-1][j] + taken * v[row-1]);
			}
			best[row][i] = sol;
			//cout << sol << '\t';
		}
		//cout << endl;
	}
	return best[n][r];
}

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	REP(i,t) {
		cout << "Case #" << (i+1) << ": " << solve() << endl;
	}
}
