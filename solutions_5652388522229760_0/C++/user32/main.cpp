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

void Digits(int64_t N, set<int>& d) {
  assert(N > 0);
  while (N > 0) {
    d.erase(N % 10);
    N /= 10;
  }
}

int64_t F(int64_t N) {
  if (N == 0) {
    return -1;
  }

  set<int> digits;
  for (int i = 0; i < 10; ++i) {
    digits.insert(i);
  }

  int64_t K;
  for (int i = 1; ; ++i) {
    K = N * i;
    Digits(K, digits);
    if (digits.empty()) {
      break;
    }
  }

  return K;
}

void Solve() {
  int N;
  cin >> N;

  int64_t result = F(N);
  if (result == -1) {
    cout << "INSOMNIA";
  } else {
    cout << result;
  }
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
    cout << endl;
  }

  return 0;
}
