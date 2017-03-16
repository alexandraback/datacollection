#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll T;
  scanf("%lld", &T);
  for(ll cas=1; cas<=T; cas++) {
    ll n;
    scanf("%lld", &n);
    if(n==0) {
      printf("Case #%lld: INSOMNIA\n", cas);
    } else {
      ll at = n;
      ll seen = 0;
      vector<int> S(10);
      while(true) {
        ll tmp = at;
        while(tmp > 0) {
          S[tmp%10]=true;
          tmp/=10;
        }

        bool done = true;
        for(ll i=0; i<S.size(); i++) {
          if(!S[i]) {
            done = false;
          }
        }
        if(done) { break; }

        at += n;
      }
      printf("Case #%lld: %lld\n", cas, at);
    }
  }
}

