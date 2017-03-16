#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
  int T;
  cin >> T;
  for(int te = 1; te <= T; ++te) {
    int K, C, S;
    cin >> K >> C >> S;
    int req = (K + C - 1) / C;
    if (S < req) goto impossibru;
    cout << "Case #" << te << ":";
    for(int i = 1; i <= K; i += C) {
      ll idx = 1;
      int st = i;
      int en = i + C - 1;
      if (en > K) {
        en = K;
        // cout << st << " " << en << endl;
        idx = st;
        ll sz = K;
        int p = 1;
        for(int j=st+1;j<=en;j++) {
          idx += sz * (j-1);
          sz *= K;
          ++p;
        }
        for(;p<C;++p) {
          idx += sz * (en-1);
          sz *= K;
          ++p;
        }
      } else {
        // cout << ":" << st << " " << en << endl;
        idx = st;
        ll sz = K;
        for(int j=st+1;j<=en;j++) {
          idx += sz * (j-1);
          sz *= K;
        }
      }
      cout << " " << idx;
    }
    cout << endl;
    continue;
    impossibru:
    cout << "Case #" << te << ": IMPOSSIBLE" << endl;
  }
}
