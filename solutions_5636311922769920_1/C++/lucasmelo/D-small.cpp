#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb(x) push_back(x)

#ifdef DEBUG
#include "/Users/lucasmelo/Topcoder/debug.h"
#define dbg(args...) do {cerr << #args << ": "; debug,args; cerr << endl;} while(0)
#else
#define dbg(args...)
#endif

ll K, C, S;

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    printf("Case #%d:", cn);

    cin >> K >> C >> S;

    vector<ll> sol;

    int nxt = 0;

    for(int i=0; i< (K + C - 1)/C; i++) {
      ll pos = 0;
      ll len = 1;
      for(int j=0; j<C; j++) {

        pos += ((++nxt) % K) * len;
        len *= K;
      }
      sol.pb(pos + 1);
    }


    if (S < (ll)sol.size()) {
      printf(" IMPOSSIBLE\n");
    } else {
      for(auto x : sol) {
        printf(" %lld", x);
      }
      printf("\n");
    }
  }
  return 0;
}
