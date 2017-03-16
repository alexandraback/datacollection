#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll T;
  scanf("%lld", &T);
  for(ll cas=1; cas<=T; cas++) {
    char buf[1000];
    scanf("%s", buf);
    vector<int> A(strlen(buf), false);
    for(ll i=0; i<A.size(); i++) {
      A[i] = (buf[i] == '+');
    }

    ll ans = 0;
    bool flipped = false;
    for(ll i=A.size()-1; i>=0; i--) {
      if(!(A[i] ^ flipped)) {
        ans++;
        flipped = !flipped;
      }
    }
    printf("Case #%lld: %lld\n", cas, ans);
  }
}
