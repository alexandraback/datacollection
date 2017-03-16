#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

long long mysqrt(long long x) {
  long long lo = 0, hi = 1 + (1LL<<31);
  while (lo+1 < hi) {
    long long mid = (lo+hi)/2;
    if (mid*mid==x)
      return mid;
    else if (mid*mid<x)
      lo = mid;
    else
      hi = mid;
  }
  return lo;
}

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    long long r, t;
    cin >> r >> t;
    long long lo = 0, hi = mysqrt(t) + 10;
    hi = min(hi, t/(2*r+1) + 1);
    // sum_{i=0}^{k-1} 2r + 4i + 1 = (2r+1)k + 2k(k-1)
    while (lo+1 < hi) {
      long long mid = (lo+hi)/2;
      long long need = (2*r+1)*mid + 2*mid*(mid-1);
      if (need > t)
	hi = mid;
      else
	lo = mid;
    }
    printf("Case #%d: %lld\n", rr, lo);
  }
  return 0;
}
