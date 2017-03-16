#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
  int T;
  int h,w;
  int g[111][111];
  int tate[111],yoko[111];
  scanf("%d", &T);
  for(int I = 1; I <= T; I++) {
    printf("Case #%d: ",I);
    scanf("%d%d", &h, &w);
    fill(tate,tate+111,0);
    fill(yoko,yoko+111,0);
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        scanf("%d", g[i]+j);
        tate[j] = max(g[i][j],tate[j]);
        yoko[i] = max(g[i][j],yoko[i]);
      }
    }
    bool res = true;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if( yoko[i] > g[i][j] && tate[j] > g[i][j] ) res = false;
      }
    }
    puts(res?"YES":"NO");
  }
}
