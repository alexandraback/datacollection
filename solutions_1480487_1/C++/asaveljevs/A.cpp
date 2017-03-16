#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define PRINT(format, args...) do { fprintf(stdout, format, ## args); fflush(stdout); } while (0)

#define SIZE(__c) (int)(__c).size()
#define FOREACH(__i, __c) for (typeof(__c.begin()) __i=__c.begin(); __i!=__c.end(); ++__i)

typedef signed long long int i64;

int main() {
  int t, T;
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    int i, j, k, N, S;
    int sc[206];
    double lo, hi, ml, s, p;
    scanf("%d", &N);
    S=0;
    for (i=0; i<N; i++) {
      scanf("%d", &sc[i]);
      S+=sc[i];
    }
    PRINT("Case #%d:", t);
    for (i=0; i<N; i++) {
      lo=0;
      hi=1;
      for (j=0; j<64; j++) {
        ml=(lo+hi)/2;
        s=sc[i]+S*ml;
        p=0;
        for (k=0; k<N; k++)
          if (k!=i && sc[k]<s)
            p+=(s-sc[k])/S;
        if (p>=1-ml)
          hi=ml;
        else
          lo=ml;
      }
      PRINT(" %.6lf", 100*hi);
    }
    PRINT("\n");
  }
  return 0;
}
