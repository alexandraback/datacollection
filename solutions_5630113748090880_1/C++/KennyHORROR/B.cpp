#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

int x[5000];

void Solve() {
  memset(x, 0, sizeof x);
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      int v;
      cin >> v;
      x[v] ^= 1;
    }
  }
  for (int i = 0; i < 5000; ++i) {
    if (x[i]) {
      cout << " " << i;
    }
  }
  cout << endl;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d:", i + 1);
        Solve();
    }
    return 0;
}
