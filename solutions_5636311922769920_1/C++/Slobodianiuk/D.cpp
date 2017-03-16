#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vector<long long> VI;
typedef vector<VI> VVI;

void solve(const long long &k, const long long &c, const long long &s) {
  VI pows(c);
  long long cur = 1;
  for (long long i = 0; i < c; ++i) {
    pows[i] = cur;
    cur *= k;
  }
  long long m;
  for (int i = 0; i < 1 + (k-1) / c; ++i) {
    m = 1;
    for (int j = 0; j < c; ++j) {
      m += pows[j] * ((c * i + j) % k);
    }
    cout << " " << m;
  }
  cout << "\n";
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  freopen("D-large.in", "rt", stdin);
  freopen("outputl.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    long long k, c, s;
    cin >> k >> c >> s;
    if (s * c < k) {
      printf("Case #%d: IMPOSSIBLE\n", line+1);
    } else {
      printf("Case #%d:", line+1);
      solve(k, c, s);
    }
  }

  return 0;
}
