#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

#define EPS (1e-9)
using namespace std;

int TT,N,NA;
long double D,A;
vector<long double> T;
vector<long double> X;

int main(void) {
  scanf("%d",&TT);
  REP(t,TT) {
    scanf("%LF",&D); scanf("%d",&N); scanf("%d",&NA);
    T.resize(N); X.resize(N);
    REP(n,N) {
      scanf("%LF",&T[n]); 
      scanf("%LF",&X[n]);
    }

    printf("Case #%d:\n",t+1);

    long double t0 = T[0];
    long double x0 = X[0];
    long double t1 = (N==1?T[0]:T[1]);
    long double x1 = (N==1?X[0]:X[1]);

    REP(a,NA) {
      scanf("%LF",&A);

      long double odpoved = 0;

      if (N > 1) {
        long double jaciel = sqrt(D/0.5/A);
        long double onciel = (D-x0) / ((x1-x0)/(t1-t0));


        if (onciel < jaciel+EPS) {   // on je skor
          odpoved = jaciel;
        }
        else {
          odpoved = onciel;
        }
      }
      else {
        odpoved = sqrt(D/0.5/A);
      }

      printf("%.9LF\n",odpoved);
    }
  }
  return 0;
}
