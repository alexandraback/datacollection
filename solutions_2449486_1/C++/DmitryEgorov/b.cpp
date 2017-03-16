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

int n, m, A[110][110], R[110], C[110];

int main()
{
  int tst, cnt, i, j;
  bool fl;
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &tst);
  for (cnt=1; cnt<=tst; cnt++)
  {
    scanf("%d%d", &n, &m);
    for (i=0; i<n; i++)
      for (j=0; j<m; j++)
        scanf("%d", &A[i][j]);
    for (i=0; i<n; i++)
      for (R[i]=0, j=0; j<m; j++)
        R[i]=max(R[i],A[i][j]);
    for (i=0; i<m; i++)
      for (C[i]=0, j=0; j<n; j++)
        C[i]=max(C[i],A[j][i]);
    for (fl=1, i=0; i<n; i++)
      for (j=0; j<m; j++)
        fl&=(A[i][j]==min(R[i],C[j]));
    printf("Case #%d: %s\n", cnt, (fl)?("YES"):("NO"));    
  }
  return 0;
}
