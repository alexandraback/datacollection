#include <cstdio>

using namespace std;

int z[1<<21], x[512], v[512];

void play(int s)
{
   if(s)
   {
      v[z[s]]=1;
      play(s-x[z[s]]);
   }
}

int main()
{
   int T, t, N, i, j, k, s;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d", &N);
      for(i=N; i--; scanf("%d", x+i));
      printf("Case #%d:\n", t);
      
      for(i=1<<21; i--; z[i]=0);
      for(i=N; i--; v[i]=0);
      
      for(i=1; i<1<<N; i++)
      {
         for(s=j=0; j<N; j++)
            if(1<<j&i)
            {
               s+=x[j];
               k=j;
            }
         if(!z[s])
            z[s]=k;
         else
         {
            play(s);
            for(j=0; j<N; j++)
               if(1<<j&i)
                  v[j]|=2;
            for(i=0; i<N; i++)
               if(v[i]==1)
                  printf("%d ", x[i]);
            printf("\n");
            for(i=0; i<N; i++)
               if(v[i]==2)
                  printf("%d ", x[i]);
            printf("\n");
            break;
         }
      }
      
      if(i==1<<N) printf("Impossible\n");
   }
   
   return 0;
}
