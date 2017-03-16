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

int A[1100], B[1100];
bool u[1100];
vector <int> V;

int main()
{
  int tst, cnt, i, n, cur, ocur, j, res, bid;
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &tst);
  for (cnt=1; cnt<=tst; cnt++)
  {
    cerr<<cnt<<endl;
    res=0, scanf("%d", &n);
    for (i=0; i<n; i++)
      scanf("%d%d", &A[i], &B[i]);
    memset(u,0,sizeof(u)), cur=0, V.clear();
      ocur=cur-1;
      while (ocur!=cur)
      {
        ocur=cur;
        for (j=0; j<n; j++)
          if ((!u[j]) && B[j]<=cur)
            cur+=2, res++, u[j]=1;
      }   
    for (i=0; i<2*n; i++)
    {
//      cerr<<cur<<" "<<res<<"     "<<u[0]<<" "<<u[1]<<" "<<u[2]<<" "<<u[3]<<" "<<u[4]<<endl;
      while (V.size())
      {
        sort(V.begin(),V.end());
        if (V[0]<=cur)
          cur++, V.erase(V.begin());
        else
          break;
      }
      bid=-1;
      for (j=0; j<n; j++)
        if ((!u[j]) && A[j]<=cur && (bid==-1 || B[j]>B[bid]))
          bid=j;
      if (bid==-1)
        break;
      cur++, u[bid]=1, V.pb(B[bid]);
      ocur=cur-1;
      while (ocur!=cur)
      {
        ocur=cur;
        while (V.size())
        {
          sort(V.begin(),V.end());
          if (V[0]<=cur)
            cur++, V.erase(V.begin());
          else
            break;
        }
        for (j=0; j<n; j++)
          if ((!u[j]) && B[j]<=cur)
            cur+=2, res++, u[j]=1;
      }   
    }
    (cur<2*n)?(printf("Case #%d: Too Bad\n", cnt)):(printf("Case #%d: %d\n", cnt, 2*n-res));
  }
  return 0;
}
