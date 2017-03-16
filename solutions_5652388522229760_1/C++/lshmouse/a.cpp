#include <stdio.h>
int a;
bool flag[10];

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
       scanf("%d", &a);
       for (int i = 0; i < 10;  i++) flag[i] = false;
       int count = 0;
       for(int i = 1; i < 100; i++) {
         int tmp = a * i;
         while (true) {
           int digtal = tmp % 10;
           if (flag[digtal] == false) {
              flag[digtal] = true;
              count++;
           }
           tmp =  tmp / 10;
           if (tmp == 0) break;
         }
         if (count == 10) {
           printf("Case #%d: %d\n", t, a * i);
           break;
         }
       }
       if (count < 10) {
          printf("Case #%d: INSOMNIA\n", t);
       }
    }
}
