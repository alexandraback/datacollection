#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

void Solve() {
  long long k, c, s;
  cin >> k >> c >> s;
  if (s * c < k) {
    puts("IMPOSSIBLE");
    return;
  }
  std::vector<long long> ans;
  std::vector<long long> pow;
  long long cur = 1;
  for (int i = 0; i < c; ++i) {
    pow.push_back(cur);
    cur = cur * k;
  }
  long long pos = 0;
  while (true) {
    long long v = 0;
    for (int j = c - 1; j >= 0; --j) {
      if (pos == k) {
        --pos;
      }
      v += pos * pow[j];
      ++pos;
      pos = std::min(pos, k);
    }
    ans.push_back(v + 1);
    if (pos == k) {
      break;
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
