#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;
#define iss istringstream
#define pb push_back
#define cs c_str()
#define frr(i,a,b) for(i=(a); i<(b); i++)
#define fr(i,n) frr(i,0,(n))
#define rrf(i,b,a) for(i=(b)-1; i>=(a); i--)
#define rf(i,n) rrf(i,(n),0)
#define sq(x,y,z) sqrt((x)*(x)+(y)*(y)+(z)*(z))
#define in(x,s) (s.find(x)!=s.end())
#define sv(x) sort(x.begin(),x.end())

double ncr(int n, int r)
{
   double f=1;
   int i;
   for(i=1; i<=r; i++)
   {
      f*=(n-i+1);
      f/=i;
   }
   return f;
}

int main()
{
   int T, t, i, j, n, x, y, L;
   double p, a, b, f;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d %d", &n, &x, &y);
      x=abs(x);
      L=(x+y)/2;
      
      if(n<=(2*L-1)*L)
         p=0;
      else if(n>=(2*L+1)*(L+1))
         p=1;
      else if(x==0)
         p=0;
      else
      {
         n-=(2*L-1)*L;
         if(n<y+1)
            p=0;
         else if(n>=2*L+y+1)
            p=1;
         else
         {
            //printf("%d %d\n", L, n);
            a=b=0;
            for(i=0; i<=2*L; i++)
            {
               j=n-i;
               if(0<=j && j<=2*L)
               {
                  f=ncr(n, i);
                  //printf("%d %d %lf\n", n, i, f);
                  if(i>y) a+=f;
                  b+=f;
               }
            }
            p=a/b;
         }
      }
      
      printf("Case #%d: %.6lf\n", t, p);
   }
   
   return 0;
}
