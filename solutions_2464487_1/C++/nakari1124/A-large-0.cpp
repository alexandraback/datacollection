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

typedef int nkr_int;

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
  i64 eval(i64 n) {
    return 2 * n + 2 * r - 1 - t / n;
  }

  i64 r, t;
};

void Solver::solve() {
  cin >> r >> t;

  i64 m0, m1;
  m0 = 1;
  double s0 = sqrt(double(t) * 0.5);
  m1 = i64(s0) + 1;
  i64 v0 = eval(m0);
  i64 v1 = eval(m1);

  if(v0 == 0) {
    cout << m0 << endl;
    return;
  }
  else if(v1 == 0) {
    cout << m1 << endl;
    return;
  }

  i64 ret = m0;
  while(true) {
    i64 center = (m0 + m1) / 2;

    if(m1 - m0 == 1) {
      ret = m0;
      break;
    }

    i64 vc = eval(center);
    if(vc < 0) {
      m0 = center;
      v0 = vc;
    }
    else if(vc > 0) {
      m1 = center;
      v1 = vc;
    }
    else {
      ret = center;
      break;
    }

    //cout << vc << endl;

  }

  cout << ret << endl;
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
