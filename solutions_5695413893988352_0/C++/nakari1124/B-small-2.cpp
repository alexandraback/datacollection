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
typedef unsigned long long ui64;

typedef i64 nkr_int;

typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); ++i)
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
  i64 i, j, k;

  string C, J;
  cin >> C >> J;
  i64 L = sz(C);

  reverse(all(C));
  reverse(all(J));

  i64 nm = 1;
  REP(0, L, i) {
    nm *= 10;
  }

  pair<i64, i64> ans(-1, -1);
  REP(0, nm, i) {
    bool flag1 = true;
    i64 i1 = i;
    tr(C, c1) {
      if(*c1 != '?' && i1 % 10 != *c1 - '0') {
	flag1 = false;
	break;
      }
      i1 /= 10;
    }
    if(flag1) {
      REP(0, nm, j) {
	bool flag2 = true;
	i64 j1 = j;
	tr(J, c2) {
	  if(*c2 != '?' && j1 % 10 != *c2 - '0') {
	    flag2 = false;
	    break;
	  }
	  j1 /= 10;
	}
	if(flag2) {
	  if(ans.first < 0) {
	    ans.first = i;
	    ans.second = j;
	  }
	  else {
	    i64 a1 = abs(ans.first - ans.second);
	    i64 a2 = abs(i - j);
	    if(a1 > a2) {
	      ans.first = i;
	      ans.second = j;
	    }
	    else if(a1 == a2 && i < ans.first) {
	      ans.first = i;
	      ans.second = j;
	    }
	    else if(a1 == a2 && i == ans.first && j < ans.second) {
	      ans.first = i;
	      ans.second = j;
	    }
	  }
	}
      }
    }
  }

  if(L == 1) {
    cout << ans.first << " " << ans.second << endl;
  }
  else if(L == 2) {
    printf("%02lld %02lld\n", ans.first, ans.second);
  }
  else if(L == 3) {
    printf("%03lld %03lld\n", ans.first, ans.second);
  }

  
}

int main(int argc, char *argv[]){
  i64 T;
  cin >> T;
  i64 t;

  REP(0, T, t) {
    Solver s;
    cout << "Case #" << t + 1 << ": ";
    s.solve();
  }

  return 0;
}

