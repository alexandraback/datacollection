#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int n;
char A[10240];
string dp[1024];

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
       scanf("%s", A);
       n = strlen(A);
       dp[0] = string(A, 0, 1);
       for (int i = 1; i < n ; i ++) {
           dp[i] = string(A, 0, i + 1);
           char top = A[0];

           for (int j = 0; j <=i; j++) if (A[j] > top) top = A[j];

           for (int j = 0; j <=i; j++) if (A[j] == top) {
               string tmp = string(A, j, 1) + dp[j-1] + string(A, j + 1, i - j);

               if (tmp > dp[i]) dp[i] = tmp;
           }
           // printf("%d: %s\n", i, dp[i].c_str());
       } 
       printf("Case #%d: %s\n", t, dp[n-1].c_str());
    }
}
