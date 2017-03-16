#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#ifdef DEBUG
#include "/Users/lucasmelo/Topcoder/debug.h"
#define dbg(args...) do {cerr << #args << ": "; debug,args; cerr << endl;} while(0)
#else
#define dbg(args...)
#endif

ll N;
ll cur;
bool dig[10];
int ndig;

void add_dig(ll cur) {
  while (cur > 0) {
    ll d = cur % 10;
    if (!dig[d]) {
      --ndig;
      dig[d] = true;
    }
    cur /= 10;
  }
}

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    printf("Case #%d: ", cn);
    cin >> N;

    if (N == 0){
      printf("INSOMNIA\n");
    } else {
      memset(dig, false, sizeof(dig));
      ndig = 10;
      cur = 0;
      do {
        cur += N;
        add_dig(cur);
      } while (ndig > 0);
      printf("%lld\n", cur);
    }

  }
  return 0;
}
