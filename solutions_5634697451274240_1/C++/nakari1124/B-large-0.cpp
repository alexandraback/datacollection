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
  string stack0;
  cin >> stack0;
  // trim
  string stack;
  tr(stack0, it) {
    if(*it == '+' || *it == '-') {
      stack.append(1, *it);
    }
  }

  //i64 begin, end, cur;
  auto cur = stack.end();
  i64 ans = 0;
  while(cur != stack.begin()) {
    --cur;

    if(*cur == '-') {
      // need flip
      if(stack[0] == '+') {

	auto flip_end = stack.begin();
	while(flip_end != cur && *flip_end == '+') {
	  *flip_end = '-';
	  ++flip_end;
	}
	reverse(stack.begin(), flip_end);

	++ans;
      }

      for(auto it = stack.begin();it != cur+1; ++it) {
	if(*it == '+') {
	  *it = '-';
	}
	else {
	  *it = '+';
	}
      }
      reverse(stack.begin(), cur+1);
      ++ans;
    }
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

