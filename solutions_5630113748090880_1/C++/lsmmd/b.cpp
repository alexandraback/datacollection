#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

int main() {
  int tk, tk1 = 0;
  cin >> tk;
  while (tk--) {
    tk1++;
    int n;
    cin >> n;
    vector<vector<int> > a(2 * n - 1, vector<int>(n));
    for (int i = 0; i < 2 * n - 1; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    map<int, int> mp;
    for (int i = 0; i < 2 * n - 1; i++) {
      for (int j = 0; j < n; j++) {
        mp[a[i][j]]++;
      }
    }
    cout << "Case #" << tk1 << ":";
    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (it->second % 2) {
        cout << " " << it->first;
      }
    }
    cout << endl;
  }
  return 0;
}
