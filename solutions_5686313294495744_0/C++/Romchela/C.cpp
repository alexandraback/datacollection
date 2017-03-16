#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
#include <ctime>
using namespace std;

typedef long long     ll;
typedef double        dbl;

#define X             first
#define Y             second
#define mp            make_pair
#define pb            push_back
#define sz(x)         static_cast<int>((x).size())
#define all(x)        x.begin(),x.end()

#ifdef ROMCHELA
#    define D(x)          cout<<#x<<" = "<<(x)<<endl
#    define Ds()          cout<<"------------"<<endl
#    define eprintf(...)  printf(__VA_ARGS__);
#else
#    define D(c)             static_cast<void>(0)
#    define Ds(x)            static_cast<void>(0)
#    define eprintf(...)     static_cast<void>(0)
#endif

const int maxn = 1e6 + 10;

int main() {
#ifdef ROMCHELA
  freopen("C1.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int T;
  scanf("%d", &T);
  for (int ntest = 1; ntest <= T; ntest++) {
    int n;
    scanf("%d\n", &n);
    vector< pair<string, string> > s;
    for (int i = 0; i < n; i++) {
      string a, b;
      cin >> a >> b;
      s.pb(mp(a, b));
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      int cur = 0;
      vector<int> used(n, 0);
      bool flag = true;
      while (flag) {
        flag = false;
        for (int i = 0; i < n; i++) {
          if (((mask >> i) & 1) == 0) continue;
          if (used[i]) continue;
          bool found = false;
          for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
              
              if (used[j] || (((mask >> j) & 1) == 0)) {
                if (used[k] || (((mask >> k) & 1) == 0)) {
                  if ((s[j].X == s[i].X && s[k].Y == s[i].Y)) {
                    used[i] = true;
                    flag = true;
                    found = true;
                    break;
                  }
                }
              }
            }
            if (found) break;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (used[i]) {
          cur++;
        }
      }
      ans = max(ans, cur);
    }

    printf("Case #%d: %d\n", ntest, ans);
  }

#ifdef ROMCHELA
  cerr << "\nTIME ELAPSED: " << 1. * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
  return 0;
}
