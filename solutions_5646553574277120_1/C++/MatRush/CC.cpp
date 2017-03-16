#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 123456;

bool can[MAXN];

vector<int> all;
map<int, int> mp;

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int ans = 0;
    int C, D, V;
    scanf("%d %d %d", &C, &D, &V);
    // memset(can, 0, sizeof(can));
    all.clear();
    mp.clear();
    for (int i = 0; i < D; ++i) {
      int x;
      scanf("%d", &x);
      all.push_back(x);
      mp[x] = true;
    }
    sort(all.begin(), all.end());
    int need = 0;
    long long last = 0;
    int idx = 0;
    for (long long i = 1; i <= V; ++i) {
      if (!mp.count(i)) {
        ++need;
        mp[i] = true;
      }
      long long lim = (long long)C * i + last;
      for (int j = 0; j < all.size(); ++j) {
        // if (all[j] > lim) {
        //   break;
        // }
        // idx = j;
        if (all[j] > i && all[j] <= lim) {
          lim += all[j] * C;
        }
      }
      i = lim;
      last = lim;
    }
    ans = need;
    printf("Case #%d: %d\n", T, ans);
  }
}