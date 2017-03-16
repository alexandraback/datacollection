
// UW forfiters
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))


int sum, n, s[202];

bool can_survive(int id, double val) {
   double audience = val;
   double thr = s[id] + sum * val;

   REP(i,n) if (i != id) {
      if (s[i] < thr) {
         audience += (thr - s[i]) / sum;
      }
   }
  // printf("id=%d val=%lf audiene=%lf thr=%lf\n",id,val,audience,thr);
   return audience > 1.0 + 1e-11;
}

int main()
{
   int T;
   scanf("%d" , &T);
   FOR(tc,1,T) {
      scanf("%d",&n);
      sum = 0;
      REP(i,n) { scanf("%d",&s[i]); sum += s[i]; }
    //  printf("sum=%d\n",sum);
      printf("Case #%d:",tc);
      REP(i,n) {
         double l = 0, m = 0, r = 1.0;
         REP(j,64) {
            m = (l + r) / 2;
            if (can_survive(i,m)) r = m;
            else l = m;
         }
         printf(" %.7lf",r*100);
      }
      printf("\n");
   }
    return 0;
}
