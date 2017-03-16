#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;

#define MAXT 11000000
//#define MAXT 11000

int n;
int s[6];
int p[6];
char L[6];
bool dp[1<<6];
int pos[6];

void solveCase(int tc) {
   printf("Case #%d: ", tc+1);
   scanf("%d\n", &n);
   rep(i, n) {
      scanf("%c %d %d\n", L+i, s+i, p+i);
      p[i] *= 1000;
   }
   _fill(dp, 0);
   int mask = 0;
   rep(i, n)
      if (L[i] == 'R')
         mask |= 1<<i;
   dp[mask] = true;
   int ret = inf;
   int cnt = 0;
   rep(IT, MAXT) {
      if (++cnt > 100000) break;
      if (IT%100000 == 0) fprintf(stderr, "%d %d\n", tc, IT/100000);
      int alive = 0;
      int mindist = inf;
      rep(mask, 1<<n) if (dp[mask]) {
         rep(i, n) {
            pos[i] = p[i]+s[i]*IT;
            rep(j, i) mindist = min(mindist, abs(pos[i]-pos[j]));
            rep(j, i) {
               if (((mask>>i)&1) == ((mask>>j)&1) && !(pos[j] >= pos[i]+5000 || pos[i] >= pos[j]+5000)) {
                  dp[mask] = false;
                  goto nxt;
               }
            }
         }
         alive++;
         nxt:;
      }
      if (alive == 0) {
         ret = IT-1;
         break;
      }
      rep(mask, 1<<n) if (dp[mask]) {
         rep(i, n) if (!dp[mask^(1<<i)]) {
            rep(j, n) {
               if (i == j) continue;
               if (((mask>>i)&1) != ((mask>>j)&1) && !(pos[j] >= pos[i]+5000 || pos[i] >= pos[j]+5000))
                  goto nxt2;
            }
            dp[mask^(1<<i)] = true;
            nxt2:;
         }
      }
      IT += max(1, mindist-1);
   }
   if (ret == inf) puts("Possible");
   else printf("%.6lf\n", ret/1000.0);
}

void solution()
{
   int tc;
   scanf("%d\n", &tc);
   rep(i, tc)
      solveCase(i);
}

int main()
{
#ifdef MY_JUDGE
   //freopen("my.in", "rt", stdin);
   freopen("C-small-attempt2.in", "rt", stdin);
   freopen("C-small-attempt2.out", "wt", stdout);
#endif
   solution();
#ifdef MY_JUDGE
   double time = clock()*1./CLOCKS_PER_SEC;
   fprintf(stderr, "Time: %.2lf sec\n", time);
#endif
   return 0;
} 