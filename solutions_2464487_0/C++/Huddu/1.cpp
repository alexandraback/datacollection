#include "stdio.h"
#include <math.h>
using namespace std;
#define ll long long
int main() {
  ll T;
  scanf("%lld", &T);
  for(ll x=1; x<=T; x++) {
    ll r, t;
    scanf("%lld %lld", &r, &t);
    double a = sqrt((2*r-1)*(2*r-1) + 8*t);
    double b = 2*r - 1;
    ll ans = (a - b)/4;
    printf("Case #%lld: %lld\n", x, ans);
  }
}