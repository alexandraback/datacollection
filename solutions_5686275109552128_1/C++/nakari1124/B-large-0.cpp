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

void Solver::solve() {
  i64 D, i;
  cin >> D;
  vi P(D);
  i64 Pmax = 0;
  REP(0, D, i) {
    cin >> P[i];
    Pmax = max(Pmax, P[i]);
  }

  i64 ans = Pmax;
  i64 Pd;
  REP(1, Pmax+1, Pd) {
    i64 divs = 0;
    REP(0, D, i) {
      i64 dd = 0;
      i64 r = P[i] % Pd;
      dd = (P[i] - r) / Pd;
      if(r != 0) {
	++dd;
      }

      --dd;

      if(dd < 0) {
	dd = 0;
      }

      divs += dd;
    }

    ans = min(ans, Pd + divs);
  }
  
  cout << ans << endl;
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

