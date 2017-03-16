#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

int main(){
  int te; scanf("%d", &te);
  FOR(ii,1,te){
    printf("Case #%d: \n", ii);
    int x,y,m; scanf("%d%d%d",&x,&y,&m);
    bool zmiana = false;
    bool possible = true;
    char ret[60][60];
    if (x > y){ swap(x,y); zmiana = true; }
    REP(i, x) REP(j, y) ret[i][j] = '*';
    if (x == 1){
      ret[0][0] = 'c';
      FOR(i,1,y-m-1) ret[0][i] = '.';
    } else if (x*y == m + 1){
      ret[0][0] = 'c';
    } else if (x*y == m + 2){
      possible = false;
    } else if (x == 2){
      if (m % 2){
        possible = false;
      } else {
        REP(i,y-m/2)
          ret[0][i] = ret[1][i] = '.';
        ret[0][0] = 'c';
      }
    } else if ((x * y - m) % 2 == 0){
      int w = x*y-m;
      REP(i,x)
        if (w > 0){
          ret[i][0] = ret[i][1] = '.';
          w -= 2;
        }
      FOR(j, 2, y-1)
        if (w > 0){
          ret[0][j] = ret[1][j] = '.';
          w -= 2;
        }
      FOR(i, 2, x-1)
        FOR(j, 2, y-1)
          if (w > 0){
            ret[i][j] = '.'; w--;
          }
    } else if (x*y-m < 9){
      possible = false;
    } else {
      int w = x*y-m;
      REP(i,3) REP(j,3) { ret[i][j] = '.'; w--; }
      FOR(i,3,x-1)
        if (w > 0){
          ret[i][0] = ret[i][1] = '.';
          w -= 2;
        }
      FOR(j, 3, y-1)
        if (w > 0){
          ret[0][j] = ret[1][j] = '.';
          w -= 2;
        }
      FOR(i, 2, x-1)
        FOR(j, 2, y-1)
          if (ret[i][j] == '*' && w > 0){
            ret[i][j] = '.'; w--;
          }
    }
    if (possible){
      ret[0][0] = 'c';
      if (zmiana)
        REP(j,y){
          REP(i,x) printf("%c", ret[i][j]);
          printf("\n");
        }
      else
        REP(i,x){
          REP(j,y) printf("%c", ret[i][j]);
          printf("\n");
        }
    } else {
      printf("Impossible\n");
    }
  }
	return 0;
}
