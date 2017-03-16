#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;
int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    int A, B;
    cin >> A >> B;
    long double a[A];
    for (int i = 0; i < A; ++i)
      cin >> a[i];
    long double best = B + 2;
    long double t = 1;
    for (int i = 0; i < A; ++i) {
      t *= a[i];
      best = min(best, A+B-2*i-1 + (1-t)*(B+1));
    }
    printf("Case #%d: %.7Lf\n", rr, best);
  }
  return 0;
}
