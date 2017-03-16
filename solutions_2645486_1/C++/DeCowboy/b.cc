#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 10001;

int64_t max_e, restore_e;
int n;

int64_t benefit[MAXN];
int64_t want_after[MAXN];
int64_t have[MAXN];
int64_t quant[MAXN];

pair<int64_t, int> order[MAXN];

void Solve() {
  cin >> max_e >> restore_e >> n;

  for (int i = 0; i < n; i++) {
    cin >> benefit[i];
    order[i] = make_pair(-benefit[i], i);

    have[i] = max_e;
    want_after[i] = 0;
  }

  sort(order, order + n);

  int64_t score = 0;

  for (int i = 0; i < n; i++) {
    int index = order[i].second;

    int64_t spending = std::min(have[index], std::max(have[index] + restore_e - want_after[index], 0ll));

    score += benefit[index] * spending;
    have[index] -= spending;

    quant[index] = spending;

    //cerr << "at " << index << " spending " << spending << endl;

    for (int j = 0; index + j + 1 < n; j++) {
      have[index + j + 1] = std::min(have[index + j + 1], have[index + j] + restore_e);
    }

    if (index > 0) {
      want_after[index - 1] = std::max(want_after[index - 1], have[index] + spending);

      for (int j = 0; index - j - 1 >= 0; j++) {
        want_after[index - j - 1] = std::max(want_after[index - j - 1], want_after[index - j] - restore_e);
      }
    }
  }


  int64_t current = max_e;

  for (int i = 0; i < n; i++) {
    assert(current >= quant[i]);
    current -= quant[i];
    current = std::min(max_e, current + restore_e);
  }

  cout << score << endl;
}

int main() {
  int num_cases;
  cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    cout << "Case #" << i << ": ";
    Solve();
  }
}

