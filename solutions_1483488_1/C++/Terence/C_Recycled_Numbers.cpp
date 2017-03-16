/*
 * =====================================================================================
 *
 *       Filename:  C_Recycled_Numbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年04月14日 13时02分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Terence (), thang@c2micro.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

#define N 2000010
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))

bool v[N];
int main()
{
  int t;
  scanf("%d", &t);
  for(int idx = 1; idx <= t; idx++) {
    int a, b, bs;
    scanf("%d%d", &a, &b);
    for(bs = 1; 10*bs <= a; bs *= 10);
    assert(bs <= a && a <= b && b < 10*bs);
    memset(v, false, sizeof(v));
    int ans = 0;
    for(int x = a; x <= b; x++) {
      if(v[x]) continue;
      int y = x, c = 0;
      do {
        if(y >= a && y <= b) {
          ++c;
          v[y] = true;
        }
        y = (y/10)+y%10*bs;
      } while(y != x);
      if(c > 0) ans += c*(c-1)/2;
    }
    printf("Case #%d: %d\n", idx, ans);
  }
  return 0;
}
