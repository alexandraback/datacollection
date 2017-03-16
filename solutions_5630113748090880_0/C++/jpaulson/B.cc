#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

typedef long long ll;

using namespace std;

int main() {
  ll T;
  scanf("%lld", &T);
  for(ll cas=1; cas<=T; cas++) {
    ll n;
    scanf("%lld", &n);
    vector<ll> C(2501, 0);
    for(ll i=0; i<2*n-1; i++) {
      for(ll j=0; j<n; j++) {
        ll v;
        scanf("%lld", &v);
        C[v]++;
      }
    }
    vector<ll> A;
    for(ll i=0; i<C.size(); i++) {
      //printf("%lld %lld\n", i, C[i]);
      if(C[i]%2==1) {
        A.push_back(i);
      }
    }
    assert(A.size() == n);
    sort(A.begin(), A.end());
    printf("Case #%lld:", cas);
    for(ll i=0; i<n; i++) {
      printf(" %lld", A[i]);
    }
    printf("\n");
  }
}
