#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

typedef long long ll;

ll bit_set(ll set, ll bit) {
  return (set & (1L<<bit)) > 0;
}

string show_bin(ll n) {
  string ans;
  while(n > 0) {
    ans = char('0'+(n%2))+ans;
    n/=2;
  }
  return ans;
}

int main() {
  ll T;
  scanf("%lld", &T);
  for(ll cas=1; cas<=T; cas++) {
    ll n, j;
    scanf("%lld %lld", &n, &j);
    printf("Case #%lld:\n", cas);
    ll count = 0;
    for(ll a=1LL<<(n-1); a<(1LL<<n); a++) {
      if(!bit_set(a, 0) || !bit_set(a, n-1)) { continue; }
      vector<ll> D;
      for(ll b=2; b<=10; b++) {
        vector<ll> P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(ll p : P) {
          ll v = 0;
          ll pb = 1;
          for(ll bit=0; bit<n; bit++) {
            if(bit_set(a, bit)) {
              v = (v+pb)%p;
            }
            pb = (pb*b)%p;
          }
          if(v == 0) {
            D.push_back(p);
            break;
          }
        }
      }
      if(D.size() == 9) {
        printf("%s", show_bin(a).c_str());
        for(ll i=0; i<D.size(); i++) {
          printf(" %lld", D[i]);
        }
        printf("\n");
        count++;
        if(count == j) { break; }
      }
    }
  }
}
