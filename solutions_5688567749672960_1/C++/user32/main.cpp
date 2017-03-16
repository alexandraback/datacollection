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

int64_t Reverse(int64_t N) {
  int64_t result = 0;

  while (N > 0) {
    result *= 10;

    int64_t rem = N % 10;
    result += rem;

    N /= 10;
  }

  return result;
}

int Len(int64_t N) {
  int result = 0;
  while (N > 0) {
    ++result;
    N /= 10;
  }

  return result;
}

int64_t dp1[20][20];
int64_t dp2[20][20];
int64_t nines[16];
int64_t tens[16];

int64_t Dp1(int x, int y);
int64_t Dp2(int x, int y);

int64_t Dp1(int x, int y) {
  int64_t& r = dp1[x][y];
  if (r != -1) {
    return r;
  }

  int64_t value = tens[x + y] + nines[y];
  r = value;

  int K = x + y;
  for (int u = 1; u < K; ++u) {
    int v = K - u - 1;

    int64_t value2 = 1 + nines[K] - nines[K - u];
    assert(value2 <= value);

    int64_t delta = value - value2;
    r = min(r, Dp2(u, v) + delta);
  }

  return r;
}

int64_t Dp2(int x, int y) {
  int64_t& r = dp2[x][y];
  if (r != -1) {
    return r;
  }

  r = Dp1(y, x) + 1;

  return r;
}

int64_t Do(int64_t N) {
  int64_t result = numeric_limits<int64_t>::max() / 8;

  for (int zero_count = 0; zero_count <= 14; ++zero_count) {
    int64_t NN = N;
    for (int i = 0; i <= zero_count; ++i) {
      NN /= 10;
    }
    for (int i = 0; i <= zero_count; ++i) {
      NN *= 10;
    }

    ++NN;
    if (NN > N) {
      continue;
    }

    int64_t op1 = N - NN;

    int64_t revNN = Reverse(NN);
    if (revNN != NN) {
      ++op1;
    }

    int len = Len(revNN) - 1;
    int64_t base = tens[len];
    for (int nine_count = 0; nine_count < len; ++nine_count) {
      int64_t value = base + nines[nine_count];
      if (value > revNN) {
        continue;
      }

      int64_t op2 = revNN - value;
      result = min(result, op1 + op2 + Dp1(len - nine_count, nine_count));
    }
  }

  return result;
}

void SolveSmall(int N) {
//  vector<int> H(2 * N + 1, -1);
//  vector<int> P(2 * N + 1, -1);
//  H[1] = 1;
//  queue<int> Q;
//  Q.push(1);

//  while (!Q.empty()) {
//    int v = Q.front();
//    Q.pop();

//    if (v == N) {
//      break;
//    }

//    {
//      int u = v + 1;
//      if (u < H.size() && H[u] == -1) {
//        H[u] = H[v] + 1;
//        P[u] = v;
//        Q.push(u);
//      }
//    }

//    {
//      int u = Reverse(v);
//      if (u < H.size() && H[u] == -1) {
//        H[u] = H[v] + 1;
//        P[u] = v;
//        Q.push(u);
//      }
//    }

//  }

//  cout << '\n';
//  cout << H[N] << '\n';
//  for (int v = N; v != -1; v = P[v]) {
//    if (P[v] + 1 != v) {
//      cout << P[v] << " -> " << v << '\n';
//    }
//  }

////  cout << '\n' << H[N];
}

void Solve() {
  int64_t N;
  cin >> N;

  if (N <= 10) {
    cout << N;
    return;
  }

  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));

  nines[1] = 9;
  for (int i = 2; i < 16; ++i) {
    nines[i] = nines[i - 1] * 10 + 9;
  }
  tens[0] = 1;
  for (int i = 1; i < 16; ++i) {
    tens[i] = tens[i - 1] * 10;
  }

  int64_t result = min(Do(N), 1 + Do(N - 1));

  cout << result;
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
    cout << "Case #" << tc + 1 << ": ";
    Solve();
    cout << endl;
  }

  return 0;
}
