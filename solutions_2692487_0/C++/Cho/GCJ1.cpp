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

int main()
{
   int T, t, i, j, A, N, x[128], ans, m;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &A, &N);
      for(i=N; i--; scanf("%d", x+i));
      sort(x, x+N);
      ans=N;
      m=0;
      
      if(A>1)
      {
         for(i=0; i<N; i++)
         {
            if(A>x[i])
               A+=x[i];
            else
            {
               ans<?=N-i+m;
               for(; A<=x[i]; A+=A-1, m++);
               A+=x[i];
            }
         }
         ans<?=m;
      }
   
      printf("Case #%d: %d\n", t, ans);
   }
   
   return 0;
}
