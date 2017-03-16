#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;
const int MAXN = 300;
int scores[MAXN];
double result[MAXN];
int N;
const double EPS = 0.000000000001;
int isok(double f, int which)
{
   double X = 0.0;
   for(int i =0; i < N; i++) X += scores[i];
   double whichScore = X * f + (1.0*scores[which]);
   double total = 0.0;
   for(int i = 0; i < N; i++) {
         if(i==which) continue;
         double lo = 0.0, hi = 1.0;
         double fp = 0.0;
         int found = 0;
         for(int j = 0; j < 50; j++) {
            double fnew = (lo + hi ) / 2.0;

            double newScore = X*fnew + scores[i];
            if(fabs(newScore-whichScore) <= EPS) {
               lo = fnew;
            }
            else {
               if(newScore < whichScore) {
                  lo = fnew;
               }
               else {
                  found=1;
                  hi = fnew;
                  fp = hi;
               }
            }

         }
         if(!found) return 0;
         total+= fp;
   }
   double pm = 1.0-f;
   if(fabs(total-pm)<=EPS) {
      return 1;
   }
   if(total < pm) return 1;
   return 0;


}
double solve()
{
  // cerr<<isok(0.33333333,0)<<endl;
  // return 0.0;
   double total = 0.0;
   //for(int i =0; i <N; i++) total+=scores[i];
   for(int i = 0; i < 50; i++) {

       double lo = 0.0, hi = 1.0;
       double ret = 1.0;
       for(int j = 0; j < 50; j++) {
         double mid = (lo + hi)/2.0;
         if(!isok(mid,i)) {

            hi = mid;
            ret = hi;
         }
         else {
         lo = mid;
         }
       }

       result[i] = ret*100.0;

   }


}
int main()
{
   freopen("A-large.in","r",stdin);
   freopen("A-large.out","w",stdout);
   int T;

   cin>>T;
   for(int tc = 1; tc <= T; tc++) {

    //  int N;
      cin>>N;

      for(int i = 0; i < N; i++) cin>>scores[i];

      solve();

      printf("Case #%d:",tc);

      for(int i = 0; i < N; i++) {
         printf(" %.6lf",result[i]);
      }
      printf("\n");




   }

   return 0;
}
