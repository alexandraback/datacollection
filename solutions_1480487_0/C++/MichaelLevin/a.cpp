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
#define PROBLEM_ID "A"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    vector<int> judges(n);
    double X = 0;
    for (int i = 0; i < n; ++i) {
      cin >> judges[i];
      X += judges[i];
    }
    cout << "Case #" << test_index + 1 << ":";
    for (int first = 0; first < n; ++first) {
      double low = 0;
      double high = 1;
      while (low < high * (1 - 1e-8)) {
        double medium = (low + high) / 2;
        double sum = medium;
        for (int other = 0; other < n; ++other) {
          if (other == first) {
            continue;
          }
          double min_y_other = max((judges[first] + medium * X - judges[other]) / X, 0.);
          sum += min_y_other;
        }
        if (sum >= 1.0) {
          high = medium;
        } else {
          low = medium;
        }
      }
      printf(" %.8lf", (low + high) / 2 * 100);
    }
    cout << endl;
  }
  return 0;
}
