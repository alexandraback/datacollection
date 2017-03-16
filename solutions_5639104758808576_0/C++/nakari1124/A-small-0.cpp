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
  int Smax, i;
  string str;
  cin >> Smax >> str;
  vi ct(Smax+1);
  REP(0, Smax+1, i) {
    ct[i] = str[i] - '0';
  }

  vi sums(Smax + 1);
  sums[0] = ct[0];
  REP(1, Smax+1, i) {
    sums[i] = sums[i-1] + ct[i];
  }

  int ans = 0;
  REP(1, Smax+1, i) {
    ans = max(ans, i - sums[i-1]);
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

