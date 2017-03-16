#include <string>
#include <vector>
#include <cstdio>

typedef long long ll;

using namespace std;

int main() {
  ll T;
  scanf("%lld", &T);
  for(ll cas=1; cas<=T; cas++) {
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n, 0);
    for(ll i=0; i<n; i++) {
      scanf("%lld", &A[i]);
      A[i]--;
    }
    vector<ll> CYCLE(n, 0);
    vector<ll> TRAN(n, 0);
    vector<ll> DEST(n, 0);

    for(ll i=0; i<n; i++) {
      vector<int> S(n, false);
      ll x = i;
      ll transient = 0;
      ll cycle = 0;
      while(!S[x]) {
        S[x] = true;
        transient++;
        x = A[x];
      }

      ll end = x;
      while(A[x] != end) {
        x = A[x];
        cycle++;
        transient--;
      }
      cycle++;
      transient--;
      CYCLE[i] = cycle;
      TRAN[i] = transient;
      DEST[i] = end;
      //printf("%lld %lld %lld %lld\n", i, DEST[i], TRAN[i], CYCLE[i]);
    }

    ll pairs = 0;
    ll big_cycle = 0;
    for(ll i=0; i<n; i++) {
      big_cycle = max(big_cycle, CYCLE[i]);
      if(A[A[i]]==i) {
        ll p1 = 0;
        ll p2 = 0;
        for(ll j=0; j<n; j++) {
          if(DEST[j] == i) {
            p1 = max(p1, TRAN[j]);
          }
          if(DEST[j] == A[i]) {
            p2 = max(p2, TRAN[j]);
          }
        }
        //printf("%lld %lld %lld\n", i, p1, p2);
        pairs += p1+p2+2;
      }
    }
    pairs /= 2; // counted every pair twice
    ll ans = max(pairs, big_cycle);
    printf("Case #%lld: %lld\n", cas, ans);
  }
}
