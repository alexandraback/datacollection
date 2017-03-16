#include <cstdio>
#include <algorithm>
using namespace std;

int nbTests;

int main()
{
   scanf("%d", &nbTests);
   for(int test=1; test<=nbTests; test++)
   {
      printf("Case #%d: ", test);
      int X, Y;
      scanf("%d%d", &X, &Y);
      for(int i=0; i<abs(X); i++)
      {
         if(X < 0) printf("EW");
         else printf("WE");
      }
      for(int i=0; i<abs(Y); i++)
      {
         if(Y < 0) printf("NS");
         else printf("SN");
      }
      printf("\n");
   }
}
