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
vi g[1000];
bool highest[1000];
bool used[1000];

bool dfs(int v) {
   if (used[v]) return false;
   used[v] = true;
   rep(i, l(g[v]))
      if (!dfs(g[v][i]))
         return false;
   return true;
}

void solveCase(int tc) {
   cout << "Case #" << (tc+1) << ": ";
   rep(i, 1000) g[i].clear();
   _fill(highest, 1);
   cin >> n;
   rep(i, n) {
      int k;
      cin >> k;
      rep(j, k) {
         int v;
         cin >> v;
         g[v-1].pb(i);
      }
      if (k != 0)
         highest[i] = false;
   }
   _fill(used, 0);
   rep(i, n) if (highest[i])
      if (!dfs(i)) {
         puts("Yes");
         return;
      }
      else _fill(used, 0);
   puts("No");   
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
   //freopen("my.in", "rt", stdin);
   freopen("A-small-attempt4.in", "rt", stdin);
   freopen("A-small-attempt4.out", "wt", stdout);
#endif
   solution();
#ifdef MY_JUDGE
   fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
   return 0;
}