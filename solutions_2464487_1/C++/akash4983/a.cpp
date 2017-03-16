#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <cmath>

#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;

typedef long long int LL;
typedef vector<int > VI;

LL r;
LL cost(LL n) {
   return 2*r*n + (2*n-1)*n;
}

int main() {
   int T;
   S(T);
   int c = 0;
   while(T--) {
      LL t;
      scanf("%lld%lld",&r,&t);
      LL lo,hi,mi;
      lo = 0;
      hi = min(t/(2*r),(LL)sqrt(t));
      while(1) {
         mi = (lo + hi)>>1;
         if(cost(mi) <= t && cost(mi+1) > t) break;
         
         if(cost(mi) < t) lo = mi + 1;
         else hi = mi - 1;
      }
      c++;
      printf("Case #%d: %lld\n",c,mi);
   }
   return 0;
}
