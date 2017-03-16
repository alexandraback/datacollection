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
inline const DD &DOUBLE() { static DD x; scanf("%lf", &x); return x; }
template<class T> inline void MIN(T &a, const T &b) { if (b < a) a = b; }
template<class T> inline void MAX(T &a, const T &b) { if (b > a) a = b; }
// ---------------------------------------------------------------- //

double C, F, X;
int main() {
//  ios::sync_with_stdio(false);
//  freopen("in", "r", stdin);
  int TC = INT();
  REP(tc, TC) {
    printf("Case #%d: ", tc + 1);
    C = DOUBLE();
    F = DOUBLE();
    X = DOUBLE();
    DD p = 2;
    DD S = 0;
    int t = 0;
    while (C * (p + F) < X * F) {
//      __ ++t _ NL;
      S += C / p;
      p += F;
    }
    S += X / p;
    printf("%.9lf\n", S);
  }
  return 0;
}
