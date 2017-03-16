#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VP;

int sum(const VI &nums, int mask) {
  int s = 0;
  for (int i = 0; mask; ++i) {
    if (mask & 1)
      s += nums[i];
    mask >>= 1;
    }
  return s;
  }

void outNums(const VI &nums, int mask) {
  bool first = true;
  for (int i = 0; mask; ++i) {
    if (mask & 1) {
      if (first)
        first = false;
      else
        cout << ' ';
      cout << nums[i];
      }
    mask >>= 1;
    }
  cout << '\n';
  }

int main() {
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    int n; cin >> n;

    VI nums(n);
    for (int i = 0; i < n; ++i)
      cin >> nums[i];

    cout << "Case #" << cur << ":\n";

    map<int, int> toMake; bool done = false;
    for (int i = 0; (i < (1 << n)) && !done; ++i) {
      int s = sum(nums, i);
      if (toMake.count(s)) {
        outNums(nums, i);
        outNums(nums, toMake[s]);
        done = true;
        }
      else toMake[s] = i;
      }
    
    if (!done) cout << "Impossible\n";
    }
  }

