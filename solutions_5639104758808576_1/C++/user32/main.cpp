#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>
using namespace std;

bool Can(int extra, const vector<int>& counts) {
  assert(!counts.empty());

  int cnt = counts[0] + extra;
  for (int i = 1; i < counts.size(); ++i) {
    if (cnt < i) {
      return false;
    }

    cnt += counts[i];
  }

  return true;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/A-large.in", "rb", stdin);
  freopen("../Console/A-large.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    int S;
    cin >> S;

    string line;
    cin >> line;

    vector<int> counts(S + 1);
    for (int i = 0; i <= S; ++i) {
      counts[i] = line[i] - '0';
    }

    int lo = 0, hi = 10000;
    while (lo < hi) {
      int med = (lo + hi) / 2;
      if (!Can(med, counts)) {
        lo = med + 1;
      } else {
        hi = med;
      }
    }

    cout << "Case #" << tc + 1 << ": " << lo << '\n';
  }

  return 0;
}
