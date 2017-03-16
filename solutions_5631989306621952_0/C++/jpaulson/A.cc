#include <string>
#include <vector>
#include <cstdio>

typedef long long ll;

using namespace std;

int main() {
  ll T;
  scanf("%lld", &T);
  for(ll cas=1; cas<=T; cas++) {
    char s[1001];
    scanf("%s", s);
    ll len = strlen(s);
    string ans;
    for(ll i=0; i<len; i++) {
      if(ans+s[i] > s[i]+ans) {
        ans = ans+s[i];
      } else {
        ans = s[i] + ans;
      }
    }
    printf("Case #%lld: %s\n", cas, ans.c_str());
  }
}
