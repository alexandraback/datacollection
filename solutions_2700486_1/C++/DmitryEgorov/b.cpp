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

const int maxsz = 1005;
const int maxn = 1123123;
const int maxc = 4200;

long double C[maxc+5][maxc+5];
int D[maxsz+5];

long double solve (int n, int x, int y)
{
  int lv=(x+y)/2;
  if (lv>=maxsz-2)
    return 0;
  if (lv>0 && D[lv-1]>=n)
    return 0.0;
  if (D[lv]<=n)
    return 1.0;
  int lf=n-D[lv-1];

  assert(0<lf && lf<=4*lv);
  assert(y<=2*lv);

  if (y==2*lv)
    return 0.0;


  /*if (lf>2*lv+y)
    return 1.0;
  if (lf<=y)
    return 0.0; */

  cerr<<lf<<" "<<lv<<endl;
  int i;
  long double res=0.0;
  for (i=0; i<=lf; i++)
    if (max(i,lf-min(2*lv,lf-i))>=y+1)
      res+=C[lf][i];
  return res;
}

int main()
{
  int tst, cnt, n, x, y, i, j;
  freopen("hard.in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &tst);
  for (D[0]=1, i=1; i<maxsz; i++)
    D[i]=D[i-1]+4*i+1;
  //cerr<<D[0]<<" "<<D[1]<<" "<<D[2]<<" "<<D[3]<<endl;
  assert(4*maxsz+100<=maxc);
  assert(D[maxsz-5]>=maxn);
  for (C[0][0]=1.0, i=1; i<maxc; i++)
    for (C[i][0]=C[i-1][0]/2.0, j=1; j<=i; j++)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])/2.0;
  for (cnt=1; cnt<=tst; cnt++)
  {
    scanf("%d%d%d", &n, &x, &y), x=abs(x);
    assert((x+y)%2==0 && n<=maxn);
    printf("Case #%d: %.8lf\n", cnt, (double)solve(n,x,y));
  }
  return 0;
}
