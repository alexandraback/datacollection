#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

#define PROBLEM_ID "B"

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int sum = abs(x) + y;
    int k = static_cast<int>(floor(sqrt(static_cast<double>(n))));
    while (2 * k * k - k > n) {
      --k;
    }
    while (2 * (k + 1) * (k + 1) - (k + 1) <= n) {
      ++k;
    }
    double result;
    if (2 * (k - 1) >= sum) {
      result = 1.0;
    } else if (2 * k < sum) {
      result = 0.0;
    } else {
      int this_sum = n - (2 * k - 1) * k;
      if (this_sum < y + 1) {
        result = 0.0;
      } else if (y == 2 * k) {
        result = 0.0;
      } else if (this_sum - (2 * k) >= y + 1) {
        result = 1.0;
      } else {
        vector< vector<double> > prob(this_sum + 1, vector<double>(2 * k + 1));
        prob[0][0] = 1;
        for (int step = 0; step < this_sum; ++step) {
          for (int t = 0; t <= 2 * k; ++t) {
            if (step < 2 * k) {
              prob[step + 1][t] += prob[step][t] / 2;
              if (t < 2 * k) {
                prob[step + 1][t + 1] += prob[step][t] / 2;
              }
            } else {
              if (t < 2 * k) {
                prob[step + 1][t + 1] += prob[step][t];
              }
            }
          }
        }
        result = 0;
        for (int t = y + 1; t <= 2 * k; ++t) {
          result += prob[this_sum][t];
        }
      }
    }
    cout << "Case #" << test_index + 1 << ": " << result << endl;
  }
  return 0;
}
