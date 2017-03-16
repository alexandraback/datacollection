#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll T;
  scanf("%lld", &T);
  for(ll cas=1; cas<=T; cas++) {
    ll k, c, s;
    scanf("%lld %lld %lld", &k, &c, &s);
    ll pk = 1;
    for(ll i=0; i<c; i++) {
      pk *= k;
    }
    pk--;
    if(k > 1) {
      pk /= (k-1);
    }

    printf("Case #%lld:", cas);
    if(2*s < k) {
      printf(" IMPOSSIBLE\n");
    } else {
      for(ll i=0; i<s; i++) {
        ll adj = k-1-i;
        printf(" %lld", pk*i + 1 + adj);
      }
      printf("\n");
    } 
  }
}
