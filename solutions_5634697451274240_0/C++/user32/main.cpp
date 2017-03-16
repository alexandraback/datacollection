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
  vector<int> H(1 << N, -1);
  queue<int> Q;

  int start = 0;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '-') {
      start |= (1 << i);
    }
  }

  H[start] = 0;
  Q.push(start);

  while (!Q.empty()) {
    int value = Q.front();
    Q.pop();

    string P(N, '\0');
    for (int len = 1; len <= N; ++len) {
      for (int i = 0; i < N; ++i) {
        if (value & (1 << i)) {
          P[i] = '-';
        } else {
          P[i] = '+';
        }
      }
      reverse(P.begin(), P.begin() + len);
      for (int i = 0; i < len; ++i) {
        if (P[i] == '-') {
          P[i] = '+';
        } else {
          P[i] = '-';
        }
      }

      int value2 = 0;
      for (int i = 0; i < N; ++i) {
        if (P[i] == '-') {
          value2 |= (1 << i);
        }
      }

      if (H[value2] == -1) {
        H[value2] = H[value] + 1;
        Q.push(value2);
      }
    }
  }

  cout << H[0] << endl;
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
