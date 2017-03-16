#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std ;
typedef long long ll ;
vector<ll> dat ;
vector<ll> maxes ;
ll E, N, R, O ;
int findmax(int lo, int hi) {
  int olo = 0 ;
  int ofnd = -1 ;
  ll r = 0 ;
  while (lo < hi) {
    int b = 1 ;
    while ((lo & b) == 0 && hi > lo + (b << 1))
      b <<= 1 ;
    int ind = (lo << 1) | b ;
    if (maxes[ind] > r) {
      ofnd = ind ;
      r = maxes[ind] ;
    }
    lo += b ;
  }
  while ((ofnd & 1) == 0) {
    int b = (ofnd & -ofnd) >> 1 ;
    if (maxes[ofnd] == maxes[ofnd - b])
      ofnd -= b ;
    else
      ofnd += b ;
  }
  if (maxes[ofnd] != r)
    cout << "Missed" << endl ;
  return ofnd >> 1 ;
}
ll solve(int a, int se, int b, int ee) {
  if (b <= a)
    return 0 ;
  if (ee - se >= R * (b - a))
    return 0 ;
  int mxi = findmax(a, b) ;
  if (mxi < a || mxi >= b)
    cout << "Failed." << endl ;
  ll res = 0 ;
  ll ee2 = ee - R * (b - mxi) ;
  if (ee2 < 0)
    ee2 = 0 ;
  if (se + R * (mxi - a) > E) {
    res += solve(a, se, mxi, E) + (E - ee2) * dat[mxi] ;
  } else {
    res += (se + R * (mxi - a) - ee2) * dat[mxi] ;
  }
  return res + solve(mxi+1, ee2 + R, b, ee) ;
}
int main(int argc, char *argv[]) {
   int kases ;
   scanf("%d", &kases) ;
   for (int kase=1; kase<=kases; kase++) {
      scanf("%lld %lld %lld", &E, &R, &N) ;
      dat.clear() ;
      for (int i=0; i<N; i++) {
	ll v ;
	scanf("%lld", &v) ;
	dat.push_back(v) ;
      }
      O = N ;
      while (O & (O - 1)) {
	dat.push_back(0) ;
	O++ ;
      }
      maxes.clear() ;
      for (int i=0; i<=O; i++) {
	maxes.push_back(0) ;
	maxes.push_back(dat[i]) ;
      }
      for (int b=2; b<=O; b <<= 1) {
	int ii = b >> 1 ;
	for (int i=b; i<2*O; i += 2*b)
	  maxes[i] = max(maxes[i-ii], maxes[i+ii]) ;
      }
      ll r = solve(0, E, N, 0) ;
      printf("Case #%d: %lld\n", kase, r) ;
   }
}
