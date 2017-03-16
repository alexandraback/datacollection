#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
typedef vector <int> vi;

#define INF 2000000000
#define PI 3.14159265

#define REP(i,n) for(int i=0, _n=n; i<_n; ++i)
#define FOR(i,a,n) for(int i=a,_n=n; i<=_n; ++i)
#define FOREACH(it,arr) for (__typeof((arr).begin()) it=(arr).begin(); it!=(arr).end(); it++)

#define ALL(v) (v).begin(), (v).end()

#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

int e, r, n, v[15], initE;
int memo[10][15];

int dp(int en, int idx) {
   if ( idx >= n ) return 0;
   if ( memo[en][idx] != -1 ) return memo[en][idx];
   int ret = -1;
   FOR (i, 0, en) {
      ret = max(ret, i * v[idx] + dp(min(en-i+r, initE), idx+1));
   }

   return memo[en][idx] = ret;
}

int main() {
   freopen("b12-small.in", "r", stdin);
   freopen("b12-small.out", "w", stdout);
   int T; scanf("%d", &T);
   int tcase = 0;

   while (T--) {
      memset(memo, -1, sizeof memo);
      scanf("%d %d %d", &e, &r, &n);
      initE = e;
      REP (i, n) scanf("%d", &v[i]);

      printf("Case #%d: %d\n", ++tcase, dp(e, 0));
   }
   return 0;
}
