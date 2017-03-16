#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;

char str[1003];
int main() {
   int T;
   scanf("%d", &T);
   for (int t = 0; t < T; t++) {
      scanf("%s", str); 
      printf("Case #%d: ", t+1);
      string out = "";
      out = out + str[0];
      for (int j = 1; str[j]; j++) {
         if (str[j] < out[0]) {
            out = out + str[j];
         } else {
            out = str[j] + out;
         }
      }
      printf("%s\n", out.c_str()); 
   }
   return 0;
}
