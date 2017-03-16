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
  string line;
  i64 i,j;
  getline(cin, line);

  vi count(30, 0);
  tr(line, c) {
    count[*c - 'A']++;
  }

  vi nums(10, 0);
  nums[0] = count['Z' - 'A'];
  nums[2] = count['W' - 'A'];
  nums[4] = count['U' - 'A'];
  nums[6] = count['X' - 'A'];
  nums[8] = count['G' - 'A'];

  nums[3] = count['H' - 'A'] - nums[8];
  nums[7] = count['S' - 'A'] - nums[6];
  nums[5] = count['V' - 'A'] - nums[7];

  nums[9] = count['I' - 'A'] - nums[5] - nums[6] - nums[8];
  nums[1] = count['O' - 'A'] - nums[0] - nums[2] - nums[4];

  REP(0, 10, i) {
    REP(0, nums[i], j) {
      cout << i;
    }
  }
  cout << endl;

}

int main(int argc, char *argv[]){
  i64 T;
  cin >> T;
  getchar();
  i64 t;

  REP(0, T, t) {
    Solver s;
    cout << "Case #" << t + 1 << ": ";
    s.solve();
  }

  return 0;
}

