#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SZ(a) ((int)((a).size()))
#define REPSZ(i,v) REP(i,SZ(v))
#define ALL(a) (a).begin(),(a).end()
typedef long long Int;


double main2() {
  int A, B; cin >> A >> B;
  double p[A]; REP(i, A) cin >> p[i];
  
  double ans = 2 + B;

  double ok = 1.0;
  for (int i = 1; i <= A; i++) {
      int k = A - i;
      ok *= p[i - 1];
      
      double exp = ok * (B - A + 2 * k + 1) +
          (1.0 - ok) * (B - A + 2 * k + 1 + B + 1);
      ans = min(ans, exp);
  }
  return ans;
}

int main() {
  int TNO; scanf("%d\n", &TNO);
  for(int tno = 1; tno <= TNO; tno++) {
      
    printf("Case #%d: ", tno);
    double res = main2();
    printf("%.8f\n", res);
  }
  return 0;
}

// ./a.exe < B-large.in | tee B-large.res
