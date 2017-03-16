#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
#define PROBLEM_ID "B"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int d;
    cin >> d;
    vi p(d);
    for (int i = 0; i < d; ++i) {
      cin >> p[i];
    }
    int max_p = *max_element(p.begin(), p.end());
    int result = max_p;
    for (int max_left = 1; max_left <= max_p; ++max_left) {
      multiset<int> sorted_p(p.begin(), p.end());
      int special_count = 0;
      while (!sorted_p.empty()) {
        int largest = *sorted_p.rbegin();
        if (largest <= max_left) {
          break;
        }
        sorted_p.erase(--sorted_p.end());
        int move = min(largest - max_left, max_left);
        largest -= move;
        sorted_p.insert(largest);
        ++special_count;
      }
      result = min(result, special_count + max_left);
    }
    cout << "Case #" << (test_index + 1) << ": " << result << endl;
    cerr << "Case #" << (test_index + 1) << ": " << result << endl;
  }
  return 0;
}
