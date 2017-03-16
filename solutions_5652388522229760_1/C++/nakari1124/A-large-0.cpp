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

#define INSOMNIA "INSOMNIA"

void Solver::solve() {
  i64 N, i;
  cin >> N;
  if(N == 0) {
    cout << INSOMNIA << endl;
  }
  else {
    vi flags(10, 0);
    i64 count = 1;
    i64 N_cur = N;
    while(true) {
      N_cur = N * count;
      while(N_cur != 0) {
	flags[N_cur % 10] = 1;
	N_cur /= 10;
      }
      bool asleep = true;
      REP(0, 10, i) {
	if(flags[i] == 0) {
	  asleep = false;
	  break;
	}
      }
      if(asleep)  {
	break;
      }
      
      ++count;
    }
    cout << count * N << endl;
  }
}

int main(int argc, char *argv[]){

  i64 T;
  cin >> T;
  i64 t;

  Solver s;

  REP(0, T, t) {
    cout << "Case #" << t + 1 << ": ";

    s.solve();
  }

  return 0;
}

