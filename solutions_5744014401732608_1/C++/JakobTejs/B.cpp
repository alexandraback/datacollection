#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";

    long long n, m;
    cin >> n >> m;

    if( ((long long) 1) << (n - 2) < m) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << "POSSIBLE" << endl;
      cout << 0;
      for(int j = n-3; j >= 0; --j) {
        if(m >= ((long long) 1) << j) {
          cout << 1;
          m -= ((long long) 1) << j;
        } else {
          cout << 0;
        }
      }
      cout << m << endl;

      for(int j = 1; j < n; ++j) {
        for(int h = 0; h < n; ++h) {
          cout << (h > j);
        }
        cout << endl;
      }

      // for(int j = 0; j < n; ++j) {
      //   cout << 0;
      // }
      // cout << endl;
    }
  }
  return 0;
}