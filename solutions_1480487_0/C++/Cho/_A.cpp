#include <cstdio>

using namespace std;


int main()
{
   int T, t, N, s[256], S, D, v[256], i, j, x;
   double f[256];
   
   for(scanf("%d\n", &T), t=1; t<=T; t++)
   {
      scanf("%d", &N);
      for(S=i=0; i<N; scanf("%d", s+i), S+=s[i++]*2);
      x=S/2;
      
      for(i=0; i<N; f[i++]=-1);
      D=N;
      
      for(j=N; j--; )
      {
         for(i=0; i<N; v[i++]=0);
         for(i=0; i<N; i++)
            if(f[i]<-0.5 && D*s[i]>=S)
               v[i]=1;
         for(i=0; i<N; i++)
            if(v[i])
            {
               f[i]=s[i];
               S-=s[i];
               D--;
            }
      }
      for(i=0; i<N; i++)
         if(f[i]<-0.5)
            f[i]=(double)S/D;
      
      printf("Case #%d:", t);
      for(i=0; i<N; i++)
         printf(" %.6lf", (f[i]-s[i])*100/x);
      printf("\n");
   }
   
   return 0;
}
