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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int Deg[10], A[2123123];

int main()
{
  int t, cnt, st, ca, res, tmp, i, a, b;
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  for (Deg[0]=1, i=1; i<10; i++)
    Deg[i]=Deg[i-1]*10;
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    cerr<<cnt<<endl;
    memset(A,0,sizeof(A)), res=0;
    scanf("%d%d", &a, &b);
    for (st=0; Deg[st]<=b; st++);
    while (a<=b)
    {
      tmp=a, ca=inf;
      for (i=0; i<st; i++)
      {
        if (tmp>=Deg[st-1])
          ca=min(ca,tmp); 
        tmp+=Deg[st]*(tmp%10), tmp/=10;
      }
      //cerr<<a<<" "<<ca<<endl;
      A[ca]++, a++;
    }
    for (i=0; i<2123123; i++)
      res+=(A[i]*(A[i]-1))/2;
    printf("Case #%d: %d\n", cnt, res);
  }
  return 0;
}
