#include <stdio.h>
#include <stdlib.h>

void run(const long long num[20]) {
   int flag, i, sum;
   int *check;

   check = (int *)malloc(sizeof(int) * 2000000);

   for(i=0; i<2000000; i++)
      check[i] = 0;

   for(flag=1; flag<1048576; flag++) {
      sum=0;
      for(i=0; i<20; i++)
         if ((flag >> i)&1) sum += num[i];

      if (check[sum]) {
         for(i=0; i<20; i++)
            if ((check[sum] >> i)&1) printf("%d ", num[i]);
         printf("\n");

         for(i=0; i<20; i++)
            if ((flag >> i)&1) printf("%d ", num[i]);
         printf("\n"); return;
      }
      check[sum] = flag;
   }

   printf("Impossible\n");
   free(check);
}


int main() {
   int m, i, j;

   scanf("%d", &m);
   for(i=0; i<m; i++) {
      int n;
      long long num[20];

      scanf("%d", &n); // n=20.
      for(j=0; j<n; j++)
         scanf("%lld", &num[j]);
      printf("Case #%d:\n", i+1);
      run(num);
   }
}
