#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int n;
int A[10240];

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
       scanf("%d", &n);
       for (int i = 0; i < 2501; i++)A[i] = 0;
       int tmp = 0;
       for (int i = 0; i < 2*n -1 ; i++){
          for (int j = 0; j < n; j ++) {
            scanf("%d", &tmp);
            A[tmp] ++;
          }
       }
       printf("Case #%d:", t);
       for (int i = 0; i < 2501; i++) if (A[i] % 2 == 1) printf(" %d", i);
       printf("\n");
    }
}
