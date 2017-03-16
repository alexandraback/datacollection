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

  i64 search_all(i64 idx, i64 A_cur);

  i64 A, N;
  vi s;
};

void Solver::solve() {
  i64 i;

  cin >> A >> N;
  s = vi(N);
  REP(0, N, i) {
    cin >> s[i];
  }

  sort(all(s));

  i64 ret = search_all(0, A);
  cout << ret << endl;
}

i64 Solver::search_all(i64 idx, i64 A_cur) {
  if(idx == N) {
    return 0;
  }

  i64 A_new;

  if(s[idx] < A_cur) {
    A_new = A_cur + s[idx];
    return search_all(idx + 1, A_new);
  }

  i64 ans_op2 = N - idx;
  if(A_cur == 1) {
    return ans_op2;
  }

  i64 add_count = 0;
  A_new = A_cur;
  while(s[idx] >= A_new) {
    A_new *= 2;
    A_new -= 1;
    add_count++;
  }
  i64 ans_op1 = add_count + search_all(idx + 1, A_new + s[idx]);

  return min(ans_op1, ans_op2);
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

