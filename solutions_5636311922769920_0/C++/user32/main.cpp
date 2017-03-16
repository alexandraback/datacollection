#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void Solve() {
  int K, C, S;
  cin >> K >> C >> S;

  if (K != S) {
    cout << "XXX" << endl;
    return;
  }

  for (int i = 0; i < K; ++i) {
    int64_t pos = i;
    for (int j = 1; j < C; ++j) {
      pos *= K;
      pos += i;
    }

    cout << pos + 1 << ' ' ;
  }

  cout << endl;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/input.in", "rb", stdin);
  freopen("../Console/output.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": ";
    Solve();
  }

  return 0;
}
