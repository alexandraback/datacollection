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

const i64 NUM = 1000000007;

void Solver::solve() {
  i64 N;
  cin >> N;

  vector<string> lines(N);
  vvi cars(N);
  i64 i;
  REP(0, N, i) {
    cin >> lines[i];

    i64 c_prev = -1;
    tr(lines[i], c) {
      if((*c) != c_prev) {
	cars[i].pb(*c);
      }
      c_prev = *c;
    }
  }

  vi perm(N, 0);
  REP(0, N, i) {
    perm[i] = i;
  }

  i64 ans = 0;
  do {

    bool ok = true;
    vi flag(30, 0);
    i64 c_prev = -1;
    REP(0, N, i) {
      i64 idx = perm[i];
      tr(cars[idx], c) {
	if(*c != c_prev) {
	  if(flag[*c - 'a'] != 0) {
	    ok = false;
	    break;
	  }
	  else {
	    flag[*c - 'a'] = 1;
	  }
	}
	c_prev = *c;
      }
      if(!ok) {
	break;
      }
    }

    if(ok) {
      ++ans;
      ans %= NUM;
    }
  } while(next_permutation(all(perm)));

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

