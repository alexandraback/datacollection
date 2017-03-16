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
ll r,num,m,p;
bool ok(ll k,ll num,ll m)
{
      double x,area; 
      x=(num-1)*4+k;
      area=(x+k)*num/2;
      if (m-area>=-1e-10) return true;
      return false;
}
int main()
{
    //  freopen("A-large.in","r",stdin);
     // freopen("output2.txt","w",stdout);
      int T,t;
      ll R,L,MID;
      scanf("%d",&T);
      for (t=1;t<=T;t++)
      {   
            scanf("%I64d%I64d",&r,&m);
            num=0;
            r++;
            p=(r*r-(r-1)*(r-1));
            L=1;  R=oo;  
            while (R-L>1)
            {
                  MID=(L+R)/2;
                  if (ok(p,MID,m)) L=MID;
                      else R=MID;
            }
            printf("Case #%d: %I64d\n",t,L); 
      }
      return 0;
}
