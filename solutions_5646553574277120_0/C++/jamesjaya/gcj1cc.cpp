#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    vector<int> coin;
    int c, d, v;
    cin >> c >> d >> v;
    int sz = 0;
    for (int i = 0; i < d; i++) {
      int x; cin >> x;
      coin.push_back(x);
      sz += (1 << i);
    }
    int bisa[100];
    memset(bisa, 0, sizeof bisa);
    vector<int> poss;
    for (int i = 1; i <= sz; i++) {
      int denom = 0;
      for (int j = 0; j < d; j++) {
        if ((i&(1<<j))) {
          denom += coin[j];
        }
      }
      if (denom <= v) {
        bisa[denom] = 1;
        poss.push_back(denom);
      }
    }
    int ans = 0;
    for (int i = 1; i <= v; i++) {
      if (!bisa[i]) {
        ans++;
        bisa[i] = 1;
        int psz = poss.size();
        for (int j = 0; j < psz; j++) {
          int x = poss[j]+i;
          if (x <= v) {
            bisa[x] = 1;
            poss.push_back(x);
          }
        }
        poss.push_back(i);
      }
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}