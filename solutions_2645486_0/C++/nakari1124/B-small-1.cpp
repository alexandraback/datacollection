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
#define tr(c, i) for(i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();

  i64 E, R, N;
  vi v;
};

void Solver::solve() {
  cin >> E >> R >> N;
  v = vi(N);
  i64 i;
  REP(0, N, i) {
    cin >> v[i];
  }

  vi max_gain(E + 1, 0);
  vi max_gain_next;
  i64 e, e1;
  REP(0, E + 1, e) {
    max_gain[e] = v[0] * (E - e);
  }
  for(int e=E;e>=0;--e) {
    i64 e_new = min(e + R, E);
    max_gain[e_new] = max(max_gain[e], max_gain[e_new]);
  }
  REP(1, N, i) {
    max_gain_next = vi(E + 1, 0);

    REP(0, E + 1, e) {
      REP(e, E + 1, e1) {
	max_gain_next[e] = max(max_gain_next[e],
			       max_gain[e1] + v[i] * (e1 - e));
      }
    }

    max_gain = max_gain_next;

    for(int e=E;e>=0;--e) {
      i64 e_new = min(e + R, E);
      max_gain[e_new] = max(max_gain[e], max_gain[e_new]);
    }

  }


  cout << max_gain[0] << endl;

}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver slv;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    Solver s;
    s.solve();
  }

  return 0;
}
