#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
//#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-7;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
	~__timestamper(){
		TIMESTAMP(end);
	}
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

struct Quat {
  int sgn, val;

  Quat() : sgn(1), val(0) {
    assert(sgn == 1 || sgn == -1);
    assert(0 <= val && val < 4);
  }
  Quat(int _sgn, int _val) : sgn(_sgn), val(_val) {}
  string str() const {
    assert(0 <= val && val < 4);
    string res(1, "1ijk"[val]);
    if (sgn < 0) res = "-" + res;
    return res;
  }
  bool operator==(const Quat &other) const {
    return sgn == other.sgn && val == other.val;
  }
  bool operator!=(const Quat &other) const {
    return !(*this == other);
  }
  Quat operator-() const {
    return Quat(-sgn, val);
  }
};
const Quat ONE(1, 0);
const Quat I(1, 1);
const Quat J(1, 2);
const Quat K(1, 3);

Quat operator*(const Quat &a, const Quat &b) {
  static const int tval[4][4] = {
  { 0, 1, 2, 3 },
  { 1, 0, 3, 2 },
  { 2, 3, 0, 1 },
  { 3, 2, 1, 0 }
  };
  static const int tsgn[4][4] = {
  { 1,  1,  1,  1 },
  { 1, -1,  1, -1},
  { 1, -1, -1,  1},
  { 1,  1, -1, -1}
  };
  return Quat(a.sgn * b.sgn * tsgn[a.val][b.val], tval[a.val][b.val]);
}

Quat multAll(const vector<Quat> &seq, ll x) {
  Quat res = ONE;
  forn (i, x % 4)
    for (Quat q : seq) res = res * q;
  return res;
}
ll getMinMult(vector<Quat> seq, ll x, Quat need) {
  {
    int m = sz(seq);
    int rep = min(4LL, x);
    forn (step, rep)
    forn (i, m)
      seq.pb(seq[i]);
  }
  Quat res = ONE;
  for (int i = 0; i <= sz(seq); i++) {
    if (res == need) return i;
    if (i < sz(seq)) {
      res = res * seq[i];
    }
  }
  return sz(seq) * x + 1;
}

void solve() {
  char data[11000];
  ll x;
  scanf("%*d%lld%s", &x, data);
  vector<Quat> seq;
  for (int i = 0; data[i]; i++) {
    assert(strchr("ijk", data[i]));
    seq.pb(Quat(+1, 1 + data[i] - 'i'));
  }
  eprintf("%lld\n", x);

  Quat all = multAll(seq, x);
  if (all != -ONE) {
    printf("NO\n");
    return;
  }
  ll l1 = getMinMult(seq, x, I);
  reverse(seq.begin(), seq.end());
  for (Quat &q : seq) q = -q;
  ll l2 = getMinMult(seq, x, -K);
//  eprintf("%lld %lld\n", l1, l2);
  if (l1 + l2 < sz(seq) * x) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Caught exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
