#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

set<int> fix;
set<int> neg_fix;
long long high_energy[20000];
long long low_energy[20000];

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cout << "Case #" << test << ": ";
    int e, r, n; cin >> e >> r >> n;

    vector<long long> values;
    vector<pair<long long, int> > best_values; // neg value, index (for high -> low)
    for (int i = 0; i < n; ++i) {
      long long curr; cin >> curr;
      values.push_back(curr);
      best_values.push_back(make_pair(-curr, i));
    }
    sort(best_values.begin(), best_values.end());

    long long total_value = 0;

    fix.clear();
    neg_fix.clear();
    
    for (int i = 0; i < best_values.size(); ++i) {
      int idx = best_values[i].second;
      fix.insert(idx);
      neg_fix.insert(-idx);

      set<int>::iterator it = fix.upper_bound(idx);
      set<int>::iterator neg_it = neg_fix.upper_bound(-idx);

      int high;
      if (neg_it == neg_fix.end()) {
        high = e;
      } else {
        high = MIN(low_energy[-(*neg_it)] + (idx+(*neg_it))*r, e);
      }

      int low;
      if (it == fix.end()) {
        low = 0;
      } else {
        low = MAX(0, high_energy[*it] - (*it - idx)*r);
      }

      high_energy[idx] = high;
      low_energy[idx] = low;
      total_value += MAX((high - low), 0) * values[idx];
    }

    cout << total_value << endl;
  }
  return 0;
}