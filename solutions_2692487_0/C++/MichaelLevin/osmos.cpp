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

#define PROBLEM_ID "A"

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int a, n;
    cin >> a >> n;
    vector<int> other(n);
    for (int i = 0; i < n; ++i) {
      cin >> other[i];
    }
    sort(other.begin(), other.end());
    int result = n;
    for (int leave = n; leave >= 0; --leave) {      
      ll mote = a;
      if (mote == 1 && leave > 0) {
        continue;
      }
      int curres = n - leave;
      for (int i = 0; i < leave; ++i) {
        while (mote <= other[i]) {
          ++curres;
          mote = mote * 2 - 1;
        }
        mote += other[i];
      }
      result = min(result, curres);
    }
    cout << "Case #" << test_index + 1 << ": " << result << endl;
  }
  return 0;
}
