#include <bits/stdc++.h>
#define FORE(i, c) for (__typeof ((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (int) (n) - 1; i >= 0; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define __ cerr <<
#define _ << " " <<
#define NL endl
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef double DD;
typedef long double LD;
const LL LLINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-7;
inline const int &INT() { static int x; scanf("%d", &x); return x; }
inline const LL &LONG() { static LL x; scanf("%lld", &x); return x; }
template<class T> inline void MIN(T &a, const T &b) { if (b < a) a = b; }
template<class T> inline void MAX(T &a, const T &b) { if (b > a) a = b; }
// ---------------------------------------------------------------- //

int N;

int read() {
  int x, y; scanf("%d.%d", &x, &y);
  int t = x * 1000 + y;
  return t;
}

int solve1(vector<int> A, vector<int> B) {
  int j = B.size() - 1, ret = 0;
  REPD(i, A.size()) {
    while (j >= 0 && B[j] > A[i]) --j;
    if (j < 0) break;
    --j;
    ++ret;
  }
  return ret;
}

int solve2(vector<int> A, vector<int> B) {
  set<int> S(B.begin(), B.end());
  int ret = 0;
  FORE(i, A) {
    set<int>::iterator it = S.lower_bound(*i);
    if (it == S.end()) it = S.begin(), ++ret;
    S.erase(it);
  }
  return ret;
}

int main() {
//  ios::sync_with_stdio(false);
//  freopen("in", "r", stdin);
  int TC = INT();
  REP(tc, TC) {
    printf("Case #%d: ", tc + 1);
    N = INT();
    vector<int> A, B;
    REP(i, N) A.PB(read());
    REP(i, N) B.PB(read());
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
//    FORE(i, A) __ *i _ " "; __ NL;
//    FORE(i, B) __ *i _ " "; __ NL;
    printf("%d %d\n", solve1(A, B), solve2(A, B));
  }
  return 0;
}
