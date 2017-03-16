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


string solve() {
	int N, M;
	cin >> N >> M;
	int A[100][100];
	rep(i, N) rep(j, M) cin >> A[i][j];
	int us[100];
	rep(i, 100) us[i] = 100;
	rep(i, N) {
		int h = *max_element(A[i], A[i] + M);
		rep(j, M) {
			if (A[i][j] == h) continue;
			if (us[j] < A[i][j]) return "NO";
			us[j] = A[i][j];
		}
	}
	rep(i, N) {
		int h = *max_element(A[i], A[i] + M);
		rep(j, M) {
			if (A[i][j] != min(h, us[j])) return "NO";
		}
	}
	return "YES";
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
}

