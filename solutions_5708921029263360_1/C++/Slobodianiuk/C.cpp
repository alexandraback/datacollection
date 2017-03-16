#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<long long> VI;
typedef vector<VI> VVI;

void solve (int &j, int &p, int &s, int &k) {
  int mi = min(s, k);
  cout << j * p * mi << "\n";
  for (int itj = 0; itj < j; ++itj) {
    for (int itp = 0; itp < p; ++itp) {
      for (int its = 0; its < mi; ++its) {
        int ss = (its + itp * mi + itj) % s;
        cout << itj + 1 << " " << itp + 1 << " " << ss + 1 << "\n";
      }
    }
  }
  cout << "\n";
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  //freopen("C-small-attempt0.in", "rt", stdin);
  freopen("C-large.in", "rt", stdin);
  freopen("outputCL.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    int j, p, s, k;
    cin >> j >> p >> s >> k;

    printf("Case #%d: ", line+1);
    solve(j, p, s, k);
  }

  return 0;
}
