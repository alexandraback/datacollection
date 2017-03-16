/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111
int a[MAXN][MAXN];

int main(int argc, char *argv[]){
  int T, N, M;
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t+1);
    scanf("%d%d", &N, &M);
    REP(i, N) REP(j, M) scanf("%d", &(a[i][j]));
    bool ok = true;
    REP(i, N) REP(j, M) {
      bool ook = true;
      REP(ii, N) if(a[ii][j] > a[i][j]) ook = false;
      if(ook) continue;
      ook = true;
      REP(jj, M) if(a[i][jj] > a[i][j]) ook = false;
      if(ook) continue; 
      ok = false;
      break;
    }
    if(ok) printf("YES\n");
    else   printf("NO\n");
  }
   
  return 0;
}
