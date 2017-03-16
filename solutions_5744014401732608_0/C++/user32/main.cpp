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

int64_t Dp(int i, const vector<vector<char>>& gr, vector<int64_t>& dp) {
  int64_t& r = dp[i];
  if (r != -1) {
    return r;
  }

  r = 0;
  for (int j = i + 1; j < gr.size(); ++j) {
    if (gr[i][j]) {
      r += Dp(j, gr, dp);
    }
  }

  return r;
}

bool Go(int i, int B, int64_t M, vector<vector<char>>& gr) {
  if (i == B) {
    vector<int64_t> dp(B, -1);
    dp[B - 1] = 1;

    return Dp(0, gr, dp) == M;
  }

  int len = B - i - 1;
  int NN = 1 << len;
  for (int mask = 0; mask < NN; ++mask) {
    for (int j = i + 1; j < B; ++j) {
      gr[i][j] = false;
    }

    for (int u = 0; u < NN; ++u) {
      if ((1 << u) & mask) {
        gr[i][i + 1 + u] = true;
      }
    }

    if (Go(i + 1, B, M, gr)) {
      return true;
    }

    for (int j = i + 1; j < B; ++j) {
      gr[i][j] = false;
    }
  }

  return false;
}

void Solve() {
  int B;
  int64_t M;
  cin >> B >> M;

  vector<vector<char>> gr(B, vector<char>(B, false));
  if (Go(0, B, M, gr)) {
    cout << "POSSIBLE" << endl;
    for (int i = 0; i < B; ++i) {
      for (int j = 0; j < B; ++j) {
        char ch = gr[i][j] ? '1' : '0';
        cout << ch;
      }
      cout << endl;
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/B-small-attempt0.in", "rb", stdin);
  freopen("../Console/B-small-attempt0.out", "wb", stdout);
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
