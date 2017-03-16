#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <set>
#define maxn 22
#define X first
#define Y second
using namespace std;
 
pair<string, string> data[maxn];

int one(int x) {
  int c = 0;
  while(x) {
    c += (x&1);
    x >>= 1;
  }
  return c;
}
int main() {
  int T, cas = 1;
  cin >> T;
  while(T--) {
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++) {
      cin >> data[i].X >> data[i].Y;
    }

    int ans = 0;
    for(int i = 0; i < (1<<n); i++) {
      if (n - one(i) > ans) {
        bool vis[maxn];
        memset(vis, false, sizeof vis);
        set<string> f, s;
        for(int j = 0; j < n; j++) {
          if (i & (1<<j)) {
            vis[j] = true;
            f.insert(data[j].X);
            s.insert(data[j].Y);
          }
        }
        for(int j = 0; j < n; j++) {
          for(int k = 0; k < n; k++) {
            if (vis[k]) continue;
            else {
              if (f.find(data[k].X) != f.end() && s.find(data[k].Y) != s.end()) {
                f.insert(data[k].X), s.insert(data[k].Y);
                vis[k] = true;
              }
            }
          }
        }
        int ok = 0;
        for(int j = 0; j < n; j++) {
          ok += vis[j];
        }
      //  cout << "ok = " << ok << "i = " << i << endl;
        if (ok == n) ans = max(ans, n - one(i));
      }
    }

    cout << "Case #" << cas++ << ": " << ans << endl;
  }
  return 0;
}