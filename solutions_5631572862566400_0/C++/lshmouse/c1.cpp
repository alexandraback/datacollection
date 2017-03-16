#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int n;
int A[12];
int B[12];

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
       scanf("%d", &n);
       for (int i = 0; i < n; i++) {
         scanf("%d", &A[i]);
         A[i] = A[i] - 1;
       }
       for (int i = 0; i < n; i++) B[i] = i;
       int res = 0;
       do {
         for (int i = 1; i < n; i++) {
            int cur = A[B[i]];
            if ((B[i-1] == cur || B[0] == cur) && (A[B[0]] == B[1] || A[B[0]] == B[i])) {
              if (i +1 > res) res = i + 1;
            } 
            if ((B[i - 1] != cur) && (B[(i+1) % n] != cur)) break;
         }  
       } while (next_permutation(B, B + n));
       printf("Case #%d: %d\n", t, res);
    }
}
