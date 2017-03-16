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

int main() {
	int T;
	cin >> T;
	FOR(ti, 1, T) {
		int n, m;
		cin >> n >> m;
		VVI A(n, VI(m));
		VI R(n, 0), C(m, 0);
		REP(i, n) REP(j, m) {
			cin >> A[i][j];
			R[i] = max(R[i], A[i][j]);
			C[j] = max(C[j], A[i][j]);
		}
		bool possible = true;
		REP(i, n) REP(j, m)
			if (R[i] != A[i][j] && C[j] != A[i][j])
				possible = false;
		cout << "Case #" << ti << ": ";
		if (possible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
