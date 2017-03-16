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

const char* kOne =
    "9\n"
    "1 1 2\n"
    "1 2 1\n"
    "1 3 3\n"
    "2 1 1\n"
    "2 2 3\n"
    "2 3 2\n"
    "3 1 3\n"
    "3 2 2\n"
    "3 3 1\n";

const char* kTwo =
    "18\n"
    "1 1 1\n"
    "1 1 3\n"
    "1 2 1\n"
    "1 2 2\n"
    "1 3 2\n"
    "1 3 3\n"
    "2 1 1\n"
    "2 1 2\n"
    "2 2 2\n"
    "2 2 3\n"
    "2 3 1\n"
    "2 3 3\n"
    "3 1 2\n"
    "3 1 3\n"
    "3 2 1\n"
    "3 2 3\n"
    "3 3 1\n"
    "3 3 2\n";

const char* kLarge =
    "27\n"
    "1 1 1\n"
    "1 1 2\n"
    "1 1 3\n"
    "1 2 1\n"
    "1 2 2\n"
    "1 2 3\n"
    "1 3 1\n"
    "1 3 2\n"
    "1 3 3\n"
    "2 1 1\n"
    "2 1 2\n"
    "2 1 3\n"
    "2 2 1\n"
    "2 2 2\n"
    "2 2 3\n"
    "2 3 1\n"
    "2 3 2\n"
    "2 3 3\n"
    "3 1 1\n"
    "3 1 2\n"
    "3 1 3\n"
    "3 2 1\n"
    "3 2 2\n"
    "3 2 3\n"
    "3 3 1\n"
    "3 3 2\n"
    "3 3 3\n";

struct Item {
  int j, p, s;
};

void Solve() {
  int J, P, S, K;
  cin >> J >> P >> S >> K;

  if (J == 3 && P == 3 && S == 3) {
    if (K == 1) {
      cout << kOne;
    } else if (K == 2) {
      cout << kTwo;
    } else {
      cout << kLarge;
    }
    return;
  }

  vector<Item> items;
  for (int j = 0; j < J; ++j) {
    for (int p = 0; p < P; ++p) {
      for (int s = 0; s < S; ++s) {
        items.push_back({j, p, s});
      }
    }
  }

  int N = items.size();
  int NN = 1 << N;
  vector<uint8_t> dp(NN, 0);
  vector<int> prev(NN, -1);

  for (int mask = 0; mask < NN; ++mask) {
    int cnt[3][3][3];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < N; ++i) {
      if ((1 << i) & mask) {
        ++cnt[0][items[i].j][items[i].p];
        ++cnt[1][items[i].j][items[i].s];
        ++cnt[2][items[i].p][items[i].s];
      }
    }
    for (int i = 0; i < N; ++i) {
      if ((1 << i) & mask) {
        continue;
      }

      if (cnt[0][items[i].j][items[i].p] == K) {
        continue;
      }
      if (cnt[1][items[i].j][items[i].s] == K) {
        continue;
      }
      if (cnt[2][items[i].p][items[i].s] == K) {
        continue;
      }

      int mask2 = mask ^ (1 << i);
      uint8_t value = dp[mask] + 1;
      if (dp[mask2] < value) {
        dp[mask2] = value;
        prev[mask2] = mask;
      }
    }
  }

  int mask = max_element(dp.begin(), dp.end()) - dp.begin();
  int result = dp[mask];
  cout << result << endl;

  vector<Item> way;
  for (;;) {
    int p_mask = prev[mask];
    if (p_mask == -1) {
      break;
    }

    int diff = mask ^ p_mask;
    for (int i = 0; i < N; ++i) {
      if ((1 << i) & diff) {
        way.push_back(items[i]);
      }
    }

    mask = p_mask;
  }
  assert(way.size() == result);

  reverse(way.begin(), way.end());
  for (const Item& i : way) {
    cout << i.j + 1 << ' ' << i.p + 1 << ' ' << i.s  + 1 << endl;
  }
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/C-small-attempt0.in", "rb", stdin);
  freopen("../Console/C-small-attempt0.out", "wb", stdout);
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
