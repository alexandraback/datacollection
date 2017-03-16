

#include<stdio.h>

int main() {
  int cases;
  scanf("%d",&cases);
  for(int i=0 ;i<cases;) {
    int row, col, ship;
    scanf("%d %d %d",&row,&col,&ship);
    printf("Case #%d: %d\n", ++i, (row*(col/ship))  + ((col%ship==0)? ship-1:ship));
  }
  return 0;
}
