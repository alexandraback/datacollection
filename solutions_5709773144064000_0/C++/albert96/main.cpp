#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef long double LD;

const LD ep = 1e-7;
LD C, F, X;
int main()
{
   //freopen("B-small-attempt0.in", "r", stdin);
   //freopen("B-small-attempt0.out", "w", stdout);
   int T = 0, te = 0;
   cin>>T;
   while(T--)
   {
      ++ te;
      cin>>C>>F>>X;
      LD res = 2.0*X;
      LD cr = 2.0, Ti = 0.0;
      for(int i = 1; i <= 10000000; ++ i)
      {
         if(Ti > res)
            break;
         if(X/cr < ep)
            break;
         LD ans = Ti+X/cr;
         if(ans < res)
            res = ans;
         Ti = Ti+C/cr;
         cr = cr+F;
      }
      printf("Case #%d: ", te);
      cout<<fixed<<setprecision(10)<<res<<endl;
   }
   return 0;
}
