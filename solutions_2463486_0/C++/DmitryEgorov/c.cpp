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

#define maxn 12123123

using namespace std;

int A[maxn];

bool good (long long a)
{
  long long b=0, tmp=a;
  while (tmp>0)
    b*=10, b+=(tmp%10), tmp/=10;
  return a==b;
}

int main()
{
  int tst, cnt, i;
  long long a, b, aa, bb;
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  scanf("%d", &tst);
  for (i=1; i<=maxn; i++)
    (good(i)&&good(i*1ll*i))?(A[i]=A[i-1]+1):(A[i]=A[i-1]);
  for (cnt=1; cnt<=tst; cnt++)
  {
    cin>>a>>b;
    aa=(long long)sqrt((double)a), bb=(long long)sqrt((double)b);
    aa+=5, bb+=5, bb=max(b,0ll);
    while ((aa-1)*(aa-1)>=a)
      aa--;
    while (bb*bb>b)
      bb--;
    printf("Case #%d: %d\n", cnt, A[bb]-A[aa-1]);
  }
  return 0;
}
