#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

#include <complex>
typedef long double ld;
typedef complex<ld> P;
const ld EPS=1e-8, PI=acos(-1.0);
#define EQ(a,b) (abs((a)-(b)) < EPS)

ld dot(P a, P b) { return real(conj(a)*b); }
ld cross(P a, P b) { return imag(conj(a)*b); }
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > +EPS)   return +1;    // counter clockwise
  if (cross(b, c) < -EPS)   return -1;    // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;                               // a--c--b
}

void solve() {
  int H, W, D; cin >> H >> W >> D;
  string s[H];
  REP(y, H) cin >> s[y];

  // only for small
  P cp;
  H -= 2, W -= 2;
  REP(y, H) REP(x, W) if (s[y+1][x+1] == 'X') cp = P(x+0.5, y+0.5);
  vector<double> vdir;
  double ran = 232.0 / PI;

  FOREQ(ax, -110, 110) FOREQ(ay, -110, 110) {
    P pos = P(ax*W, ay*H);
    if (ax%2==0) pos.real() += cp.real();
    else pos.real() += W - cp.real();

    if (ay%2==0) pos.imag() += cp.imag();
    else pos.imag() += H - cp.imag();

    if (abs(cp - pos) < D || EQ(abs(cp-pos), D)) if (!EQ(cp, pos)) {
      vdir.push_back(fmod(arg(pos - cp) + ran, 2*PI));
    }
  }

  // elim
  int res = 0;
  sort(vdir.begin(), vdir.end());
  REP(i, SZ(vdir)) {
    if (i == SZ(vdir)-1 || !EQ(vdir[i], vdir[i+1])) res++;
  }

  cout << res << endl;
}

int main() {
  int test_case; cin >> test_case;
  REP(t, test_case) {
    printf("Case #%d: ", t+1);
    solve();
  }
}
