#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t,a,b;
   // freopen("inl.in","r",stdin);
    //freopen("out.out","w",stdout);
    scanf("%d",&t);
    int num=0;
    while (t--)
    {
          scanf("%d%d",&a,&b);
          int i;
          double ans=b+2;
          double gl=1;
          for (i=0;i<a;i++)
          {
              double p;
              scanf("%lf",&p);
              gl=gl*p;
              if (gl*(a-1-i+1+b-1-i)+(1-gl)*(a-1-i+2+b+b-1-i)<ans)
              ans=gl*(a-1-i+1+b-1-i)+(1-gl)*(a-1-i+2+b+b-1-i);
          }
          printf("Case #%d: ",++num); 
          printf("%f\n",ans);
    }
}         
              
              
              
              
              
              
              
              
              
              
