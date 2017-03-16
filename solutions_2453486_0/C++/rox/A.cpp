#include <cstdio>
#include <cstring>

using namespace std;

char g[5][5],o[5][5],x[5][5];

bool win(char a[][5],char p)
{
  bool s,t; s=t=true;
  for(int i = 0; i < 4; i++) {
    bool ok;
    ok = true;
    for(int ii = 0; ii < 4; ii++) if(a[i][ii]!=p)ok = false;
    if(ok)return true;
    ok = true;
    for(int ii = 0; ii < 4; ii++) if(a[ii][i]!=p)ok = false;
    if(ok)return true;
    if(a[i][i]!=p)s=false;
    if(a[i][3-i]!=p)t=false;
  }
  return s||t;
}

int main(void)
{
  int T;
  scanf("%d", &T);
  for(int I = 1; I <= T; I++) {
    printf("Case #%d: ",I);
    bool done = true;
    for(int i = 0; i < 4; i++) {
      scanf("%s", g[i]);
      for(int j = 0; j < 4; j++) {
        if( g[i][j] == 'T' ) {
          o[i][j] = 'O';
          x[i][j] = 'X';
        } else {
          o[i][j] = x[i][j] = g[i][j];
        }
        if( g[i][j] == '.' ) done = false;
      }
    }
    bool a=win(o,'O'),b=win(x,'X');
    if(!a&&!b) {
      if(!done)puts("Game has not completed");
      else puts("Draw");
    }else if(a==b) {
      puts("Draw");
    } else if(a) {
      puts("O won");
    } else if(b) {
      puts("X won");
    }
  }
  return 0;
}
