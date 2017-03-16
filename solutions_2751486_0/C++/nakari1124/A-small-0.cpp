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

int is_consonant(char c) {
  switch(c) {
  case 'a':
  case 'i':
  case 'u':
  case 'e':
  case 'o':
    return 0;
  default:
    return 1;
  }
  return 1;
}

void Solver::solve() {
  string name;
  i64 n;
  i64 i;

  cin >> name;
  cin >> n;

  i64 L = sz(name);
  vi flags(L - n + 1);

  vi count(L + 1);
  count[0] = 0;
  REP(0, L, i) {
    count[i+1] = count[i] + is_consonant(name[i]);
  }

  REP(0, L - n + 1, i) {
    flags[i] = (count[i + n] - count[i] == n) ? 1 : 0;
  }

  i64 n_val = (flags[0] == 1 ? 1 : 0);
  i64 n_val_last = n_val;
  REP(1, L - n + 1, i) {
    if(flags[i] == 0) {
      n_val += n_val_last;
    }
    else {
      n_val += i + 1;
      n_val_last = i + 1;
    }
  }

  cout << n_val;
  cout << endl;
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
