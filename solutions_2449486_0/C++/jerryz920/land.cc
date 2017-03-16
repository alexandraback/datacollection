/******************************************************************************

 @File Name : {PROJECT_DIR}/land.cc

 @Creation Date : 13-04-2013

 @Created By: Zhai Yan

 @Purpose :

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

static void solve(int c)
{
  printf("Case #%d: ", c);
  int m, n;
  scanf("%d%d", &m, &n);

  int l[m][n];
  bool checked[m][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &l[i][j]);
      checked[i][j] = false;
    }
  }

  bool flag = true;

  for (int h = 1; h <= 2; h++) {
    for (int i = 0; i < m; i++) {
      flag = true;
      if (l[i][0] > h)
        continue;
      for (int j = 0; j < n; j++) {
        if (l[i][j] > h) {
          flag = false;
          break;
        }
      }
      if (flag) {
        for (int j = 0; j < n; j++) {
          checked[i][j] = true;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      flag = true;
      if (l[0][j] > h)
        continue;
      for (int i = 0; i < m; i++) {
        if (l[i][j] > h) {
          flag = false;
          break;
        }
      }
      if (flag) {
        for (int i = 0; i < m; i++) {
          checked[i][j] = true;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (l[i][j] == h && !checked[i][j]) {
          printf("NO\n");
          return ;
        }
      }
    }
  }
  printf("YES\n");
}


int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    solve(i);
  }
  return 0;
}
