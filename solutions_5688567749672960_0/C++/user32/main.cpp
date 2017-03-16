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

int Reverse(int N) {
  int result = 0;

  while (N > 0) {
    result *= 10;

    int rem = N % 10;
    result += rem;

    N /= 10;
  }

  return result;
}

void Solve() {
  int64_t N;
  cin >> N;

  vector<int> H(2 * N + 1, -1);
  H[1] = 1;
  queue<int> Q;
  Q.push(1);

  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();

    if (v == N) {
      break;
    }

    {
      int u = v + 1;
      if (u < H.size() && H[u] == -1) {
        H[u] = H[v] + 1;
        Q.push(u);
      }
    }

    {
      int u = Reverse(v);
      if (u < H.size() && H[u] == -1) {
        H[u] = H[v] + 1;
        Q.push(u);
      }
    }

  }

  cout << H[N];
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/A-small-attempt0.in", "rb", stdin);
  freopen("../Console/A-small-attempt0.out", "wb", stdout);
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
