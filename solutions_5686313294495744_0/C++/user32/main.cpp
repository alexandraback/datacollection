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

int Count(int idx, int mask, const vector<string>& A, const vector<string>& B) {
  bool has_a = false, has_b = false;
  for (int i = 0; i < A.size(); ++i) {
    if ((1 << i) & mask) {
      if (A[i] == A[idx]) {
        has_a = true;
      }
      if (B[i] == B[idx]) {
        has_b = true;
      }
    }
  }

  if (has_a && has_b) {
    return 1;
  }

  return 0;
}

int Dp(int mask,
       const vector<string>& A,
       const vector<string>& B,
       vector<int>& dp) {
  int& r = dp[mask];
  if (r != -1) {
    return r;
  }

  r = 0;
  for (int i = 0; i < A.size(); ++i) {
    if ((1 << i) & mask) {
      int mask2 = mask ^ (1 << i);
      r = max(r, Count(i, mask2, A, B) + Dp(mask2, A, B, dp));
    }
  }

  return r;
}

void Solve() {
  int N;
  cin >> N;

  vector<string> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }

  vector<int> dp(1 << N, -1);
  dp[0] = 0;

  cout << Dp((1 << N) - 1, A, B, dp) << endl;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
    freopen("../Console/input", "rb", stdin);
    freopen("../Console/output", "wb", stdout);
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
