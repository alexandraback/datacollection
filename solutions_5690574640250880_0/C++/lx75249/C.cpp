#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define see(x) cerr<<#x<<" = " << (x) << endl
using namespace std;
char ans[60][60];
int main()
{
  freopen("C-small-attempt1.in","r",stdin);
  //freopen("C-small-attempt0.in","r",stdin);
  freopen("C-out","w",stdout);
  int T, R, C, M;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    scanf("%d%d%d",&R,&C,&M);
    int m = R*C-M;
    //printf("Case #%d: %d X %d, space: %d, mine: %d\n", t, R, C, m, M);
    printf("Case #%d:\n", t);
    if (R==1 || C==1)
    {
      for(int i=1;i<=R;i++)
      {
        for(int j=1;j<=C;j++)
        {
          if (i==1 && j==1)
          {
            printf("c");
            m--;
            continue;
          }
          if (m==0)
            printf("*");
          else printf("."),m--;
        }
        printf("\n");
      }
      continue;
    }
    if (m == 1)
    {
      for(int i=1;i<=R;i++)
      {
        for(int j=1;j<=C;j++)
          if (i==1 && j==1)
          {
            printf("c");
          }
          else
            printf("*");
        printf("\n");
      }
      continue;
    }
    if (m==2 || m==3)
    {
      printf("Impossible\n");
      continue;
    }
    memset(ans,0,sizeof(ans));
    bool rev = R>C;
    if (R>C)
      swap(R,C);
    //R<C
    bool outputed = false;
    for(int A=2; A<=R; A++)
    {
      int B=m/A;
      if (B>C)
        continue;
      if (m==5 || m==7)
      {
        printf("Impossible\n");
        outputed = true;
        break;
      }
      int r = m-A*B;
      for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
        {
          ans[i][j]='*';
          if (i<=A && j<=B)
            ans[i][j]='.';
        }
      ans[1][1]='c';
      if (r==0)
      {
      }
      if (r==1)
      {
        if (A<3 || B<3)
          continue;
        if (A>=3 && B<C)
        {
          ans[1][B+1]='.';
          ans[2][B+1]='.';
          ans[A][B]='*';
        } else
        if (B>=3 && A<R)
        {
          ans[A][B]='*';
          ans[A+1][1]='.';
          ans[A+1][2]='.';
        }
      }
      if (r>1)
      {
        if (B<C)
          for(int i=1;i<=r;i++)
            ans[i][B+1]='.';
        else 
          for(int i=1;i<=r;i++)
            ans[A+1][i]='.';
      }
      if (rev)
        for(int i=1;i<=C;i++)
        {
          for(int j=1;j<=R;j++)
            printf("%c", ans[j][i]);
          printf("\n");
        }
      else
        for(int i=1;i<=R;i++)
        {
          for(int j=1;j<=C;j++)
            printf("%c", ans[i][j]);
          printf("\n");
        }
      outputed = true;
      break;
    }
    if (!outputed)
      printf("Impossible\n");
  }
}
