#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ca = 1; T--; ++ca) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    cout << "Case #" << ca << ":" << endl;
    vector<int> subset(n*100000+1, -1);
    bool found = false;
    for (int bm = 0; bm < (1<<n) && !found; ++bm) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (((bm>>i)&1) == 1) {
          sum += s[i];
        }
      }
      if (subset[sum] != -1) {
        found = true;
        bool first = true;
        for (int i = 0; i < n; ++i) {
          if (((bm>>i)&1) == 1) {
            if (first) {
              first = false;
            }
            else {
              cout << " ";
            }
            cout << s[i];
          }
        }
        cout << endl;
        first = true;
        for (int i = 0; i < n; ++i) {
          if (((subset[sum]>>i)&1) == 1) {
            if (first) {
              first = false;
            }
            else {
              cout << " ";
            }
            cout << s[i];
          }
        }
        cout << endl;
      }
      else {
        subset[sum] = bm;
      }
    }
    if (!found) {
      cout << "Impossible" << endl;
    }
  }
}
