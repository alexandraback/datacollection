#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define ll long long 
#define oo 1000000000
#define pi acos(-1.0)
using namespace std;  
double m;
int r,num;
int main()
{
   //   freopen("A-small-attempt0.in","r",stdin);
   //   freopen("output.txt","w",stdout);
      int T,t;
      scanf("%d",&T);
      for (t=1;t<=T;t++)
      {   
            scanf("%d%lf",&r,&m);
            num=0;
            r++;
            m-=(r*r-(r-1)*(r-1));
            while (m>=-0.000001)
            {
                  num++;
                  r+=2;
                  m-=(r*r-(r-1)*(r-1));
            }
            printf("Case #%d: %d\n",t,num); 
      }
      return 0;
}
