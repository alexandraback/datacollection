// {{{
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#define REP(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))
#define DEBUG(x) { cerr << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
#define INF 1023456789
using namespace std;

typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> TRI;
typedef vector<int> VI;
typedef vector<VI> VVI;
// }}}

bool won(char C, const vector<string>& S) {
	REP(i, 4) {
		bool row = true;
		REP(j, 4)
			if (S[i][j] != C && S[i][j] != 'T')
				row = false;
		if (row)
			return true;
	}
	REP(i, 4) {
		bool col = true;
		REP(j, 4)
			if (S[j][i] != C && S[j][i] != 'T')
				col = false;
		if (col)
			return true;
	}
	bool diag = true;
	REP(i, 4)
		if (S[i][i] != C && S[i][i] != 'T')
			diag = false;
	if (diag)
		return true;
	REP(i, 4)
		if (S[i][3 - i] != C && S[i][3 - i] != 'T')
			return false;
	return true;
}

int main() {
	int T;
	cin >> T;
	FOR(ti, 1, T) {
		vector<string> S(4);
		REP(i, 4)
			cin >> S[i];
		cout << "Case #" << ti << ": ";
		if (won('X', S)) {
			cout << "X won" << endl;
		} else if (won('O', S)) {
			cout << "O won" << endl;
		} else {
			bool ended = true;
			FORE(i, S) FORE(j, *i)
				if (*j == '.')
					ended = false;
			if (ended) {
				cout << "Draw" << endl;
			} else {
				cout << "Game has not completed" << endl;
			}
		}
	}
}
