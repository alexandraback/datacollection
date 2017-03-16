#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

inline bool ok(vector<string> & cars) {
  set<char> foo;
  for (int i = 0; i < cars.size() - 1; i++) {
    char es = cars[i][0];
    if (foo.count(es))
      return false;
    char e = cars[i][cars[i].size() - 1];
    char s = cars[i + 1][cars[i + 1].size() - 1];
    if (e != s) {
      foo.insert(e);
    }
  }
  return true;
}

int resolve(vector<string> & cars) {
  int times = 0;
  sort(cars.begin(), cars.end());
  do {
    if (ok(cars))
      times++;
  } while (next_permutation(cars.begin(), cars.end()));
  return times;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    clog << t << endl;
    vector<string> cars;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      cars.push_back(s);
    }
    cout << "Case #" << t << ": " << resolve(cars) << endl;
  }
  return 0;
}

