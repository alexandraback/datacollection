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

typedef unsigned long long ui64;

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};


void Solver::solve() {
  i64 N, J;
  cin >> N >> J;

  cout << endl;
  i64 j, n;
  REP(0, J, j) {
    cout << "1";
    REP(0, (N - 2) / 2, n) {
      i64 bit = 1 << n;
      if((j & bit) != 0) {
	cout << "11";
      }
      else {
	cout << "00";
      }
    }
    cout << "1 3 4 5 6 7 8 9 10 11" << endl;
  }
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

