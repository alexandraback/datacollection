#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <list>
#include <queue>
using namespace std;
static const int SIZE = 1e7;

char sieve[SIZE];

int main(int argc, char const *argv[])
{
  int t=0;
  scanf("%d\n", &t);
  for (int idx = 0; idx < t; ++idx)
  {
    int x=0, y=0;
    scanf("%d %d\n", &x, &y);
    char fx = 'E', bx = 'W', fy = 'N', by = 'S';
    if(x < 0) {
      fx = 'W';
      bx = 'E';
    }
    if(y < 0) {
      fy = 'S';
      by = 'N';
    }
    x = x>0?x:-x;
    y = y>0?y:-y;
    int curX = 0, curY = 0;
    printf("Case #%d: ", idx+1);
    while(curX != x) {
      printf("%c%c", bx, fx);
      curX++;
    }
    while(curY != y) {
      printf("%c%c", by, fy);
      curY++;
    }
    printf("\n");
  }
  
  return 0;
}