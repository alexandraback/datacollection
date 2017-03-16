#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

int zt;
ll r, t;

ll meh(ll a, ll b, ll n) { //i'm too old for this
  ll num = (b-a)/4 + 1;
  int m = a % 4;
  if (log(num)+log(m) > log(n)+.000001) return 0;
  n -= num*m;
  a -= m; b -= m;
  n /= 4, a /= 4, b /= 4;
  if (log(a-1)+log(num) > log(n)+.000001) return 0;
  n -= (a-1)*num;
  b -= (a-1); a = 1;
  
  return b < 710000000 && b*(b+1)/2 <= n;
}

int main() {
  scanf("%d", &zt);
  for (int izz=0; izz<zt; ++izz) {
    scanf("%lld%lld", &r, &t);
    
    ll lo = 0, hi = 1000000000;
    ll mid;
    
    while (lo < hi) {
      mid = (lo + hi + 1) / 2;
      if (meh(r*2+1, 4*mid+2*r+1, t)) {
	lo = mid;
      }
      else {
	hi = mid-1;
      }
    }
    printf("Case #%d: %d\n", izz+1, lo+1);
  }
  
  return 0;
}