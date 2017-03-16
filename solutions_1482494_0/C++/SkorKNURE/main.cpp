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

int n;
int a[1000];
int b[1000];
char used[1000];

void solveCase(int tc) {
   printf("Case #%d: ", tc+1);
   cin >> n;
   rep(i, n)
      cin >> a[i] >> b[i];
   _fill(used, 0);
   int ret = 0;
   int have = 0;
   for ( ;; ) {
      int k = -1;
      rep(i, n) if (used[i] != 2 && b[i] <= have) {
         k = i;
         break;
      }
      if (k != -1) {
         if (used[k] == 0) have += 2;
         else have++;
         used[k] = 2;
         ret++;
         continue;
      }
      rep(i, n) if (!used[i] && a[i] <= have) {
         if (k == -1 || b[k] < b[i])
            k = i;
      }
      if (k == -1) {
         bool allUsed = 1;
         rep(i, n) if (used[i] != 2) {
            allUsed = 0;
            break;
         }
         if (!allUsed)
            ret = -1;
         break;
      }
      used[k] = 1;
      have++;
      ret++;
   }
   if (ret == -1) puts("Too Bad");
   else printf("%d\n", ret);
}

void solution()
{
   int tc;
   scanf("%d", &tc);
   rep(i, tc)
      solveCase(i);
}

int main()
{
#ifdef MY_JUDGE
   freopen("B-small-attempt0.in", "rt", stdin);
   freopen("B-small-attempt0.out", "wt", stdout);
#endif
   solution();
#ifdef MY_JUDGE
   double time = clock()*1./CLOCKS_PER_SEC;
   fprintf(stderr, "Time: %.2lf sec\n", time);
#endif
   return 0;
} 