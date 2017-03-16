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

int main() {
   freopen("a-1small.in", "r", stdin);
   freopen("a-1small.out", "w", stdout);
   int T; scanf("%d", &T);
   int tcase = 0;

   while (T--) {
      int r, t; scanf("%d %d", &r, &t);

      int cnt = 0;
      int white = r;
      while ( t > 0 ) {
         int black = white + 1;
         int blackArea = black * black;
         int whiteArea = white * white;
         t -= (blackArea - whiteArea);
         if ( t < 0 ) break;
         white = black + 1;
         ++cnt;
      }

      printf("Case #%d: %d\n", ++tcase, cnt);
   }
   return 0;
}
