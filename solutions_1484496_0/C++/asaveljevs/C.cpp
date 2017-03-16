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

int mk[20*100000+1];

int main() {
  int t, T;
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    int i, N, s, m, f, nb[20];
    scanf("%d", &N);
    for (i=0; i<N; i++)
      scanf("%d", &nb[i]);
    memset(mk, -1, sizeof mk);
    PRINT("Case #%d:\n", t);
    for (m=1; m<(1<<N)-1; m++) {
      s=0;
      for (i=0; i<N; i++)
        if (m&(1<<i))
          s+=nb[i];
      if (mk[s]>=0) {
        for (i=0, f=1; i<N; i++)
          if (mk[s]&(1<<i)) {
            if (!f)
              PRINT(" ");
            PRINT("%d", nb[i]);
            f=0;
          }
        PRINT("\n");
        for (i=0, f=1; i<N; i++)
          if (m&(1<<i)) {
            if (!f)
              PRINT(" ");
            PRINT("%d", nb[i]);
            f=0;
          }
        PRINT("\n");
        goto NEXT;
      }
      else
        mk[s]=m;
    }
    PRINT("Impossible\n");
    NEXT:;
  }
  return 0;
}
