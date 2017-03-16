#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int bff[1100];
int bffr[1100];
int mark[1100];

int knot[1100];
int maxL[1100];

int loop(int start) {
   memset(mark, 0, sizeof(mark));
   int count = 1;
   mark[start] = count;
   int cur = start;

   while (mark[bff[cur]] == 0) {
      cur = bff[cur];
      count++;
      mark[cur] = count;
   }
   return count+1-mark[bff[cur]];
}

void loop2(int start) {
   memset(mark, 0, sizeof(mark));
   int count = 1;
   mark[start] = count;
   int cur = start;

   while (mark[bff[cur]] == 0) {
      cur = bff[cur];
      count++;
      mark[cur] = count;
   }
   if (count+1-mark[bff[cur]] == 2) {
      knot[cur] = 1;
      knot[bff[cur]] = 1;
      if (mark[bff[cur]] > maxL[bff[cur]]) {
         maxL[bff[cur]] = mark[bff[cur]];
      }
   }
}

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 0; t < T; t++) {
      int N;
      scanf("%d", &N);
      for (int n = 0; n < N; n++) {
         scanf("%d", bff+n);
         bff[n]--;
         bffr[bff[n]] = n;
      }

      memset(knot, 0, sizeof(knot));
      memset(maxL, 0, sizeof(maxL));

      int m = 0;
      for (int i = 0; i < N; i++) {
         int len = loop(i);
         if (len > m) m = len;
      }
      for (int i = 0; i < N; i++ ){
         loop2(i);
      }
      int l = 0;
      for (int i = 0; i < N; i++ ) {
         if (knot[i]) {
            l += maxL[i];
         }
      }
      if (l > m) m = l;

      printf("Case #%d: ", t+1); 
      printf("%d\n", m);
   }
   return 0;
}
