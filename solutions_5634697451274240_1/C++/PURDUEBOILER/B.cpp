#include<stdio.h>
#include<stdlib.h>

int main() {
   int T;
   char s[1000];
   scanf("%d", &T);
   for (int t = 0; t < T; t++) {
      scanf("%s", s);

      int count = 0;
      char prev = 0;
      for (int i = 0; s[i]; i++) {
         if (s[i] == '-') {
            if (prev == '+') {
               count += 2;
            } else if (prev == 0) {
               count++;
            }
         }
         prev = s[i];
      }
      printf("Case #%d: %d\n", t+1, count);
   }
   return 0;
}
