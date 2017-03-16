#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>
#include <limits>

using namespace std;

int main() {
#ifdef LOCAL_HOST
  freopen("A-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cout.sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int n = 1; n <= N; ++n) {
    int smax;
    cin >> smax;
    string s;
    cin >> s;
    int m = (int)s.size();
    int need = 0, total = 0;
    for (int i = 0; i < m; ++i) {
      if (s[i] != '0') {
        int d = max(0, i - total);
        need += d;
        total += d;
      }
      total += s[i] - '0';
    }
    cout << "Case #" << n << ": " << need << endl;
  }

  return 0;
}
