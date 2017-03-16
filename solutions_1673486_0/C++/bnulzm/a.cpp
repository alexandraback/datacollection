#include <stdio.h>

double pro[100010];
int A, B;

double solve() {
       double pre = 1.0;
       double ans = B+2; 
             
       for (int i = 0; i <= A; ++i) {
           pre *= pro[i];
           double tmp = (1-pre)*(A-i+B-i+B+2)+pre*(A-i+B-i+1);
           if (ans > tmp) ans = tmp;      
       }
       return ans;       
}

int main() {
    int kase;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d", &kase);
    int h = 1;
    while (kase--) {
          scanf("%d %d", &A, &B);
          pro[0] = 1;
          for (int i = 1; i <= A; ++i) {
              scanf("%lf", &pro[i]);
          }
          printf("Case #%d: ", h++);
          printf("%.6f\n", solve());
    }
    return 0;
}
