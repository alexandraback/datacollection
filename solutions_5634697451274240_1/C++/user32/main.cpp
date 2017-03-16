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
  string S;
  cin >> S;

  int N = S.size();
  int result = 0;

  int i = N - 1;
  char current = '+';
  while (i >= 0) {
    if (S[i] != current) {
      ++result;
      current = S[i];
    }
    while (i >= 0 && S[i] == current) {
      --i;
    }
  }

  cout << result << endl;
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
