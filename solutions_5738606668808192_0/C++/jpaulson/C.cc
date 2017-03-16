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
    for(ll a=0; a<(1<<n); a++) {
      if(!bit_set(a, 0) || !bit_set(a, n-1)) { continue; }
      vector<ll> D;
      for(ll b=2; b<=10; b++) {
        ll v = 0;
        for(ll bit=n-1; bit>=0; bit--) {
          v *= b;
          if(bit_set(a, bit)) {
            v++;
          }
        }
        //printf("%s %lld %lld\n", show_bin(a).c_str(), b, v);
        for(ll i=2; i*i<=v; i++) {
          if(v%i==0) {
            D.push_back(i);
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

    //printf("Case #%lld: %lld\n", cas, ans);
  }
}
