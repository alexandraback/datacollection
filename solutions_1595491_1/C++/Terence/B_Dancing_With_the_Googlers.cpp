/*
 * =====================================================================================
 *
 *       Filename:  B_Dancing_With_the_Googlers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年04月14日 13时29分51秒
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

#define N 1000
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))


int main()
{
  int nCase;
  scanf("%d", &nCase);
  for(int idx = 1; idx <= nCase; idx++) {
    int n, s, p, t, c = 0;
    scanf("%d%d%d", &n, &s, &p);
    for(int i = 0; i < n; i++) {
      scanf("%d", &t);
      if(t > 3*(p-1))
        ++c;
      // 3*p-3 = (p-2) + (p-1) + p
      // 3*p-4 = (p-2) + (p-2) + p
      else if(t >= 3*p-4 && s && p >= 2) {
        ++c; --s;
      }
    }
    printf("Case #%d: %d\n", idx, c);
  }
  return 0;
}


