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

#define D (1e9)
using namespace std;

int T,N;
vector<long long> S;
long long sum;

bool check(int kto, long long kolko) {
  long long body = S[kto]*D + sum * kolko; 
  long long spolu = 0;
  REP(i,SIZE(S)) {
    if (i==kto) spolu+=kolko;
    else if (S[i]*D <= body) {
      long long x = (body - S[i]*D+sum-1) / sum;
      if (S[i]*D == body) x = 1;
      spolu += x;
    }
  }
  if (spolu > D) return true;

  return false;
}

int main(void) {
  scanf("%d",&T);
  REP(t,T) {
    S.resize(0);
    scanf("%d",&N);
    S.resize(N);
    REP(n,N) scanf("%lld",&S[n]);

    sum = 0;
    REP(i,SIZE(S)) { sum+=S[i]; }
  
    vector<long long> out;

    REP(i,SIZE(S)) {
      long long lo = 0;
      long long hi = D;
      if (!check(i,0)) {
        while(hi-lo>1) {
          long long mid = (lo+hi)/2; 
          if (check(i,mid)) hi = mid;
          else lo = mid;
        }
      }
      else hi = 0;
      out.push_back(hi);
    }
    printf("Case #%d: ",t+1);
    REP(i,SIZE(out)) {
      printf("%.8Lf",((long double)out[i]*100) / ((long double)D));
      if (i==SIZE(out)-1) printf("\n");
      else printf(" ");
    }
  }

  return 0;
}
