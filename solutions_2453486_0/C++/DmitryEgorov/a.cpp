#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <assert.h>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

char s[10][10];

int main()
{
  int tst, cnt, i, j;
  bool fl, fl2;
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &tst);
  for (cnt=1; cnt<=tst; cnt++)
  {
    printf("Case #%d: ", cnt);
    for (i=0; i<4; i++)
      scanf(" %s", s[i]);

    for (fl=0, i=0; i<4; i++, fl|=fl2)
      for (fl2=1, j=0; j<4; j++)
        fl2&=(s[i][j]=='X' || s[i][j]=='T');
    for (i=0; i<4; i++, fl|=fl2)
      for (fl2=1, j=0; j<4; j++)
        fl2&=(s[j][i]=='X' || s[j][i]=='T');
    for (fl2=1, j=0; j<4; j++)
      fl2&=(s[j][j]=='X' || s[j][j]=='T');
    fl|=fl2;
    for (fl2=1, j=0; j<4; j++)
      fl2&=(s[j][3-j]=='X' || s[j][3-j]=='T');
    fl|=fl2;
    if (fl)
    {
      puts("X won");
      continue;
    }

    for (fl=0, i=0; i<4; i++, fl|=fl2)
      for (fl2=1, j=0; j<4; j++)
        fl2&=(s[i][j]=='O' || s[i][j]=='T');
    for (i=0; i<4; i++, fl|=fl2)
      for (fl2=1, j=0; j<4; j++)
        fl2&=(s[j][i]=='O' || s[j][i]=='T');
    for (fl2=1, j=0; j<4; j++)
      fl2&=(s[j][j]=='O' || s[j][j]=='T');
    fl|=fl2;
    for (fl2=1, j=0; j<4; j++)
      fl2&=(s[j][3-j]=='O' || s[j][3-j]=='T');
    fl|=fl2;
    if (fl)
    {
      puts("O won");
      continue;
    }


    for (fl=0, i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (s[i][j]=='.')
          fl=1;
    (fl)?(puts("Game has not completed")):(puts("Draw"));
  }
  return 0;
}
