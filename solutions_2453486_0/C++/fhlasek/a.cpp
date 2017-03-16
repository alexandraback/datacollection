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

char m[5][5];

bool win(char c) {
  bool ok;
  REP(i, 4) {
    ok = true;
    REP(j, 4) if(m[i][j] != c && m[i][j] != 'T') ok = false;
    if(ok) return true;
    ok = true;
    REP(j, 4) if(m[j][i] != c && m[j][i] != 'T') ok = false;
    if(ok) return true;
  }
  ok = true;
  REP(i, 4) if(m[i][i] != c && m[i][i] != 'T') ok = false;
  if(ok) return true;
  ok = true;
  REP(i, 4) if(m[i][3-i] != c && m[i][3-i] != 'T') ok = false;
  return ok;
}

int main(int argc, char *argv[]){
  int T; 
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t + 1);
    REP(i, 4) scanf("%s", m[i]);
    if(win('X')) { printf("X won\n"); continue; }
    if(win('O')) { printf("O won\n"); continue; }
    bool full = true;
    REP(i, 4) REP(j, 4) if(m[i][j] == '.') full = false;
    if(full) printf("Draw\n");
    else printf("Game has not completed\n");
  }
  return 0;
}
