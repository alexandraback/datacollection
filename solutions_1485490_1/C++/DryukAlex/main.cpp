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

int n, m;
ll dp[101][101];
ll cnt1[101], cnt2[101];
ll type1[101], type2[101];

ll get(int a, int b) {
   if (a == n || b == m) return 0;
   if (dp[a][b] != -1) return dp[a][b];
   ll ret = 0;
   ret = max(ret, get(a+1, b));
   ret = max(ret, get(a, b+1));
   if (type1[a] == type2[b]) {
      int A = a, B = b;
      ll c1 = cnt1[A];
      ll c2 = cnt2[B];
      ll cur = 0;
      while (c1 || c2) {
         ll taken = min(c1, c2);
         c1 -= taken;
         c2 -= taken;
         cur += taken;
         ret = max(ret, get(A+1, B+1)+cur);
         if (!c1 && !c2) break;
         while (c1 == 0 && A != n) {
            A++;
            if (type1[A] == type2[B]) {
               c1 = cnt1[A];
               break;
            }
         }
         while (c2 == 0 && B != m) {
            B++;
            if (type1[A] == type2[B]) {
               c2 = cnt2[B];
               break;
            }
         }
         if (A >= n || B >= m) break;
      }
   }
   return dp[a][b] = ret;
}

void solveCase(int tc) {
   cout << "Case #" << (tc+1) << ": ";
   cin >> n >> m;
   rep(i, n) cin >> cnt1[i] >> type1[i];
   rep(i, m) cin >> cnt2[i] >> type2[i];
   _fill(dp, -1);
   ll ret = get(0, 0);
   cout << ret << endl;
}

void solution()
{
   int tc;
   cin >> tc;
   rep(i, tc)
      solveCase(i);
}

int main()
{
#ifdef MY_JUDGE
   freopen("C-large.in", "rt", stdin);
   freopen("C-large.out", "wt", stdout);
#endif
   solution();
#ifdef MY_JUDGE
   fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
   return 0;
}