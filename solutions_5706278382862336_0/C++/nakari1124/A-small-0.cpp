#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;

typedef i64 nkr_int;

typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

#define IMPOSSIBLE "impossible"
template<typename T> T gcd(T a, T b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a % b);
}

void Solver::solve() {
  i64 P, Q;
  scanf("%lld/%lld\n", &P, &Q);

  i64 g = gcd(P, Q);
  P /= g;
  Q /= g;

  i64 qn = 0;
  i64 Q0 = Q;
  while(Q0 % 2 == 0) {
    Q0 >>= 1;
    qn++;
  }
  if(Q0 != 1) {
    cout << IMPOSSIBLE << endl;
    return;
  }

  i64 Q1 = Q;
  i64 ans = 0;
  REP(0, 40, ans) {
    if(P >= Q1) {
      cout << ans << endl;
      return;
    }
    Q1 >>= 1;
  }
  cout << IMPOSSIBLE << endl;
}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

