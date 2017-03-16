#include <stdio.h>
#include <string.h>

char in[1024];
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
       scanf("%s", in);
       int n = strlen(in);
       int ret = 0;
       for(int i = 0; i < n; i++){
          if (in[i] == '-') {
             if (i > 0) ret++; // flip [0, i-1] to all -
             int j = i;
             while ((j + 1) < n && in[j + 1] == '-') j++;
             ret++; // flip all - as possible
             i = j;
          }
       }
       printf("Case #%d: %d\n", t, ret);
    }
}
