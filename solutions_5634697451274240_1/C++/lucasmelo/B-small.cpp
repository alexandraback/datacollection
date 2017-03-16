#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef DEBUG
#include "/Users/lucasmelo/Topcoder/debug.h"
#define dbg(args...) do {cerr << #args << ": "; debug,args; cerr << endl;} while(0)
#else
#define dbg(args...)
#endif

string s;

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    int ans = 0;
    printf("Case #%d: ", cn);
    cin >> s;
    size_t n = s.size();
    for(size_t i = 0; i < n-1; ++i) {
      if (s[i] != s[i+1]) {
        ++ ans;
      }
    }
    if (s[n-1] == '-') ++ ans;
    printf("%d\n", ans);
  }
  return 0;
}
