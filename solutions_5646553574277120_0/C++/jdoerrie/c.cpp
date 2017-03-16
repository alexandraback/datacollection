// #include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

using I = int32_t;
using LL = int64_t;
using II = pair<I,I>;
template<class T> using Vec = vector<T>;
template<class T> using VV = vector<vector<T>>;

LL testcase() {
  int C, D, V;
  cin >> C >> D >> V;
  Vec<I> coins(D);
  for (auto& c: coins) {
    cin >> c;
  }

  while(true) {
    int cnt = 0;
    Vec<I> is_poss(V + 1);
    is_poss[0] = 1;
    for (int m = 0; m < (1 << coins.size()); ++m) {
      int curr_sum = 0;
      for (size_t i = 0; i < coins.size(); ++i) {
        if (m & (1 << i)) {
          curr_sum += coins[i];
        }
      }

      if (curr_sum <= V) {
        cnt += (1 - is_poss[curr_sum]);
        is_poss[curr_sum] = 1;
      }
    }

    if (cnt == V) {
      return coins.size() - D;
    }

    int missing = 0;
    while (is_poss[missing]) {
      ++missing;
    }

    coins.push_back(missing);
    // cerr << missing << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cout << "Case #" << t+1 << ": " << testcase() << "\n";
  }

  return 0;
}
