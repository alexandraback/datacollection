#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

char A[4][4];
bool check(char c) {
	rep(i, 4) {
		bool ok = true;
		rep(j, 4) if (A[i][j] != c && A[i][j] != 'T') ok = false;
		if (ok) return true;
	}
	rep(i, 4) {
		bool ok = true;
		rep(j, 4) if (A[j][i] != c && A[j][i] != 'T') ok = false;
		if (ok) return true;
	}
	bool ok = true;
	rep(i, 4) if (A[i][i] != c && A[i][i] != 'T') ok = false;
	if (ok) return true;
	ok = true;
	rep(i, 4) if (A[3-i][i] != c && A[3-i][i] != 'T') ok = false;
	if (ok) return true;

	return false;
}

string solve() {
	rep(i, 4) rep(j, 4) cin >> A[i][j];
	if (check('O')) return "O won";
	if (check('X')) return "X won";
	bool draw = true;
	rep(i, 4) rep(j, 4) if (A[i][j] == '.') draw = false;
	if (draw) return "Draw";
	else return "Game has not completed";
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
}

