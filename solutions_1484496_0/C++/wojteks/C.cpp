
// UW forfiters
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
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

const int max_n = 10000000;
pair<LL, LL> w[max_n];
LL t[505];
int n,T;

bool try_and_write() {
   int m = min(n,60);
   REP(i,max_n) {
      LL sum = 0;
      LL mask = rand(), tmp = 0;
      mask = (mask<<32) + rand();
      REP(j,m) if (mask&(1LL<<j)) { sum += t[j]; tmp += (1LL<<j); }
      w[i] = MP(sum,tmp);
   }
   sort(w, w + max_n);
   REP(i,max_n-1) {
      if (w[i].FI == w[i+1].FI && w[i].SE != w[i+1].SE) {
         LL inter = (w[i].SE & w[i+1].SE);
         w[i].SE -= inter;
         w[i+1].SE -= inter;
         LL sum1 = 0, sum2 = 0;
         REP(j,m) if (w[i].SE & (1LL<<j)) { printf("%lld ",t[j]); sum1 += t[j]; } printf("\n");
         REP(j,m) if (w[i+1].SE & (1LL<<j)){ printf("%lld ",t[j]); sum2 += t[j]; } printf("\n");
         assert(sum1 == sum2);
         return true;
      }
   }
   return false;
}

int main()
{
   srand(getpid());
   scanf("%d", &T);
   FOR(tc,1,T) {
      scanf("%d",&n);
      REP(i,n) scanf("%lld", &t[i]);
      random_shuffle(t, t + n);
      printf("Case #%d:\n",tc);
      while (1) {
         if (try_and_write()) break;
      }
   }
   return 0;
}
