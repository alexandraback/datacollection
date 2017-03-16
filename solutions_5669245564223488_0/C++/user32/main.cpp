#include <algorithm>
#include <functional>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;

// const int64_t kMod = 1000000007;

bool IsValid(const std::string& train) {
  std::string collapsed;
  for (char ch : train) {
    if (collapsed.empty()) {
      collapsed.push_back(ch);
    } else {
      if (collapsed.back() != ch) {
        collapsed.push_back(ch);
      }
    }
  }

  size_t actual_size = collapsed.size();
  std::sort(collapsed.begin(), collapsed.end());
  size_t real_size = std::unique(collapsed.begin(), collapsed.end()) - collapsed.begin();

  return actual_size == real_size;
}

int64_t Solve() {
  int N;
  cin >> N;

  std::vector<std::string> cars(N);
  std::vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> cars[i];
    P[i] = i;
  }

  std::string train;

  int result = 0;
  do {
    train.clear();
    for (int i = 0; i < N; ++i) {
      train += cars[P[i]];
    }

    if (IsValid(train)) {
      ++result;
    }
  } while (std::next_permutation(P.begin(), P.end()));

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
//  std::freopen("/Users/kuznetsovs/Hobby/Console/Console/1.txt", "rb", stdin);
  std::freopen("/Users/kuznetsovs/Hobby/Console/Console/B-small-attempt0.in", "rb", stdin);
//  std::freopen("/Users/kuznetsovs/Hobby/Console/Console/A-small-attempt0.out2", "wb", stdout);
  int T;
  cin >> T;

  for (int tc = 0; tc < T; ++tc) {
    cout << "Case #" << tc + 1 << ": " << Solve() << '\n';
  }
  return 0;
}
