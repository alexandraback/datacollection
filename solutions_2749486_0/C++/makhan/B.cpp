#include <cstdio>

void go(int dx, int dy) {
  int x=0, y=0;

  while (x<dx) {
    printf("WE");
    x++;
  }
  while (x>dx) {
    printf("EW");
    x--;
  }
  while (y<dy) {
    printf("SN");
    y++;
  }
  while(y>dy) {
    printf("NS");
    y--;
  }
  
}

int main() {
  int T,x,y;
  scanf("%d",&T);
  for (int tc=1; tc<=T; tc++) {
    scanf("%d %d",&x,&y);
    printf("Case #%d: ",tc);
    go(x,y);
    printf("\n");
  }
}
