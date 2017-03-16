#include "stdio.h"
#include <algorithm>
#include <limits.h>
using namespace std;
#define ll long long
ll A[105];
ll req(ll & current, ll next) {
  if (current ==  1) return (1e6);
  ll ans = 0;
  while(current < next) {
    current += current - 1;
    ans++;
  }
  if(current == next) {
    current += current-1;
    ans++;
  }
  return ans;
}
int main() {
  ll t;
  scanf("%lld", &t);
  for(ll x=1; x<=t; x++) {
    ll a,n;
    scanf("%lld %lld", &a, &n);
    for(ll y=0; y<n; y++) {
      scanf("%lld", &A[y]);
    }
    sort(A, A+n);
    ll B[n+1];
    ll mass = a;
    B[0] = n;
    ll added = 0;
    for(ll z=0; z<n; z++) {
      ll req_z = req(mass, A[z]);
      added += req_z;
      B[z+1] = added + n-(z+1);
      mass += A[z];
    }
    B[n] = added;
    ll ans = 1e9;
    for(ll w=0; w<=n; w++) {
      ans = B[w] < ans ? B[w] : ans;
    }
    printf("Case #%lld: %lld\n", x, ans);
  }
}