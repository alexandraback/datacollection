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
#define PROBLEM_ID "C"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

bool FindTwoSubsetsSimple(const vector<int>& a, int n, vector<int>& first, vector<int>& second) {
  for (int mask = 1; mask < (1 << n); ++mask) {
    int other = (((1 << n) - 1) ^ mask);
    for (int mask2 = other; mask2; mask2 = ((mask2 - 1) & other)) {
      int sum1 = 0;
      int sum2 = 0;
      for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1) {
          sum1 += a[i];
        } else if ((mask2 >> i) & 1) {
          sum2 += a[i];
        }
      }
      if (sum1 == sum2) {
        first.clear();
        second.clear();
        for (int i = 0; i < n; ++i) {
          if ((mask >> i) & 1) {
            first.push_back(a[i]);
          } else if ((mask2 >> i) & 1) {
            second.push_back(a[i]);
          }
        }
        return true;
      }
    }
  }
  return false;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> first, second;
    cerr << "Case #" << test_index + 1 << ":" << endl;
    bool res = FindTwoSubsetsSimple(a, n, first, second);
    cout << "Case #" << test_index + 1 << ":" << endl;
    if (!res) {
      cout << "Impossible" << endl;
    } else {
      for (int i = 0; i < first.size(); ++i) {
        cout << first[i] << ' ';
      }
      cout << endl;
      for (int i = 0; i < second.size(); ++i) {
        cout << second[i] << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
