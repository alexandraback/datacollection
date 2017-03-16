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

void Out(const vector<vector<char>>& gr) {
  int B = gr.size();
  for (int i = 0; i < B; ++i) {
    for (int j = 0; j < B; ++j) {
      char ch = gr[i][j] ? '1' : '0';
      cout << ch;
    }
    cout << endl;
  }
}

int64_t Calc(const vector<vector<char>>& gr) {
  int B = gr.size();
  vector<int64_t> dp(B, -1);
  dp[B - 1] = 1;

  return Dp(0, gr, dp);
}

void Solve() {
  int B;
  int64_t M;
  cin >> B >> M;

  vector<int64_t> dp(B, -1);
  dp[B - 1] = 1;
  vector<vector<char>> gr(B, vector<char>(B, false));

  for (int i = 0; i < B; ++i) {
    for (int j = i + 1; j < B; ++j) {
      gr[i][j] = true;
    }
  }

  if (Dp(0, gr, dp) < M) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  cout << "POSSIBLE" << endl;
  if (M == dp[0]) {
    Out(gr);
    return;
  }

  gr[0][B - 1] = false;
  for (int i = B - 2, shift = 0; i > 0; --i, ++shift) {
    if (M & (1LL << shift)) {
      gr[0][i] = true;
    } else {
      gr[0][i] = false;
    }
  }

  assert(M == Calc(gr));
  Out(gr);
}

int main() {
  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/B-large.in", "rb", stdin);
  freopen("../Console/B-large.out", "wb", stdout);
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
