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

const int lenbuf = 4123123;
const int maxlen = 4123;                      

char s[lenbuf];
string Str[531123];
int D[maxlen][5], e;

int main()
{
  int tst, cnt, i, j, k, cost, cr, len, it, res;

  freopen("dict.in", "r", stdin);
  while (gets(s)!=0)
    Str[e++]=string(s,s+strlen(s));

  assert(e==521196 && e<531123);
  cerr<<"!!!!"<<endl;

  freopen("easy.in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d ", &tst);
  for (cnt=1; cnt<=tst; cnt++)
  {
    gets(s), len=strlen(s);
    for (i=0; i<=len; i++)
      for (j=0; j<5; j++)
        D[i][j]=inf;
    assert(len<=maxlen);
    D[0][0]=0;
    for (i=0; i<len; i++)
      for (j=0; j<5; j++)
        if (D[i][j]<inf/2) 
          for (it=0; it<e; it++)
          {
            if (i+(int)Str[it].length()>len)
              continue;
            cost=0, cr=j;
            for (k=0; k<(int)Str[it].length(); k++, cr--)
              if (s[i+k]!=Str[it][k])
              {
                if (cr>0)
                {
                  cost=inf;
                  break;
                }
                cr=5, cost++;
              }
            cr=max(cr,0);
            D[i+Str[it].length()][cr]=min(D[i+Str[it].length()][cr],D[i][j]+cost);
          }
    for (res=inf, i=0; i<5; i++)
      res=min(res,D[len][i]);
    assert(res<inf/2);
    printf("Case #%d: %d\n", cnt, res);
  }
  return 0;
}
