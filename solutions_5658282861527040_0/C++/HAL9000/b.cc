#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#include <math.h>

#define DBG(a,...)
//#define DBG printf

using namespace std;

int main()
{
  int tn;
  int v = scanf("%d",&tn);
  (void)v;

  int ti = 1;
  while(tn) {

    unsigned long long A;
    unsigned long long B;
    unsigned long long K;
    unsigned long long R;

    v = scanf("%lli %lli %lli",&A,&B,&K);

    DBG("%lli %lli %lli\n",A,B,K);

    R = 0;

#if 0
    // all taken
    if (K >= A) {
      if (K >= B) {
        R = A*B;
      }
      else {
        R = A*K;
      }
      goto donn;
    }
    if (K >= B) {
      if (K >= A) {
        R = A*B;
      }
      else {
        R = B*K;
      }
      goto donn;
    }
#endif
    
#if 0
    int b;
    for (b = 63; b >= 0; b++) {
      if (K & (1ULL << b)) {
        R += 
      }
    }
    R = K*K;
#endif

    int corr = 0;
    unsigned long long a,b;
    for (a = 0; a < A; a++) {
      for (b = 0; b < B; b++) {
        if ((a&b) < K) {
          corr++;
        }
      }
    }
    R = corr;

    //donn:
    printf("Case #%d: %lld\n", ti, R);

    ti++;
    tn--;
  }

  return 0;
}
