#include <cstdio>

using namespace std;


int main()
{
   int T, t, A, B, i;
   double s, f, ans;
   
   for(scanf("%d\n", &T), t=1; t<=T; t++)
   {
      scanf("%d %d", &A, &B);
      ans=(B+2)<?(A+B+1);
      s=1;
      for(i=0; i<A; i++)
      {
         scanf("%lf", &f);
         s*=f;
         ans<?=(A-i-1)*2+B-A+1+(1-s)*(B+1);
      }
      
      printf("Case #%d: %0.6lf\n", t, ans);
   }
   
   return 0;
}
