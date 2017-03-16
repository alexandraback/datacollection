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

bool C[35][12][2];
bool D[110][110][110];

int main()
{
  int t, cnt, i, j, k, z, n, s, p, cs;
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  for (i=0; i<=10; i++)
    for (j=0; j<=10; j++)
      for (k=0; k<=10; k++)
      {
        t=max(abs(i-j),max(abs(i-k),abs(j-k)));
        if (t>=3)  
          continue;
        (t==2)?(C[i+j+k][max(i,max(j,k))][1]=1):(C[i+j+k][max(i,max(j,k))][0]=1);
      }
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {  	
    cerr<<cnt<<endl;
    scanf("%d%d%d", &n, &s, &p);
    memset(D,0,sizeof(D)), D[0][0][0]=1;
    i=n;
    for (i=0; i<n; i++)
      for (scanf("%d", &cs), j=0; j<=100; j++)
        for (k=0; k<=100; k++)
          if (D[i][j][k])
            for (z=0; z<=10; z++)
            {
              if (C[cs][z][0])
                D[i+1][j][k+(int)(z>=p)]=1;
              if (C[cs][z][1])
                D[i+1][j+1][k+(int)(z>=p)]=1;
            }
    while (!D[n][s][i])
      i--;
    printf("Case #%d: %d\n", cnt, i);
  }
  return 0;
}
