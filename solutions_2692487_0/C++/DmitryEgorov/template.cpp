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

const int maxn = 110;

int A[maxn];
long long D[3*maxn][3*maxn];

int main()
{
  int tst, cnt, i, j, nj, n, a, res;
  long long tmp;
  freopen("easy.in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &tst);
  for (cnt=1; cnt<=tst; cnt++)
  {
    scanf("%d%d", &a, &n);
    assert(n<=maxn);
    for (i=0; i<n; i++)
      scanf("%d", &A[i]);
    if (a==1)
    {
      printf("Case #%d: %d\n", cnt, n);
      continue;
    }
    for (i=0; i<=n; i++)
      for (j=0; j<=n; j++)
        D[i][j]=-inf;
    sort(A,A+n), D[0][0]=a;
    for (i=0; i<n; i++)
      for (j=0; j<=n; j++)
        if (D[i][j]>0)
        {
          D[i+1][j+1]=max(D[i+1][j+1],D[i][j]);
          tmp=D[i][j], nj=j;
          while (tmp<=A[i])
            tmp+=tmp-1, nj++;
          D[i+1][nj]=max(D[i+1][nj],tmp+A[i]);
        }
    for (res=inf, i=0; i<=n; i++)
      if (D[n][i]>=0)
        res=min(res,i);
    printf("Case #%d: %d\n", cnt, res);  
  }
  return 0;
}
