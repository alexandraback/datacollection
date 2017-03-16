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

int a, b;
double p[100000];

void solveCase(int tc) {
   printf("Case #%d: ", tc+1);
   cin >> a >> b;
   rep(i, a)
      cin >> p[i];
   double ret = b+2;
   double good = p[0];
   for (int i = 1; i <= a; i++) {
      int clr = a-i;
      int rest = b-i;
      int keysGood = clr+rest+1;
      int keysBad = keysGood+b+1;
      double cur = good*keysGood + (1-good)*keysBad;
      ret = min(ret, cur);
      good *= p[i];
   }
   printf("%.6lf\n", ret);
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
   freopen("A-small-attempt0.in", "rt", stdin);
   freopen("A-small-attempt0.out", "wt", stdout);
#endif
   solution();
#ifdef MY_JUDGE
   double time = clock()*1./CLOCKS_PER_SEC;
   fprintf(stderr, "Time: %.2lf sec\n", time);
#endif
   return 0;
} 