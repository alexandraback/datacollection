#include <bits/stdc++.h>

#define REP(i,n)    for(int i=0;i<(n);++i)

using namespace std;

int main() {
  int t;
  cin>>t;
  REP(cnt, t) {
    uint64_t k,c,s;
    cin>>k>>c>>s;
    cout << "Case #" << (cnt+1) << ": ";
    if (k > c*s) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    for (int i = 0; i < k; i += c) {
      uint64_t index = 1;
      uint64_t pow = 1;
      bool ok = false;
      for (int j = 0; j < c; ++j) {
        if (i+j >= k) {
          ok = true;
          break;
        }
        index += (i+j) * pow;
        pow *= k;
      }
      cout << ' ' << index;
      if (ok) break;
    }
    cout << endl;
  }
  return 0;
}
