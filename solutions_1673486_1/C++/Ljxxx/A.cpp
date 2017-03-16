#include <cstdio>
#include <cstring>
#include <cstdlib>

double p[100000];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    scanf("%d", &t);
    for(int cas = 1;cas <= t;cas ++) {
        int A, B;
        scanf("%d%d", &A, &B);
        for(int i = 0;i < A;i ++) scanf("%lf", &p[i]);
        
        double pro = 1;
        for(int i = 0;i < A;i ++) {
            pro *= p[i];
            p[i] = 1-pro;
        }
        
        double res = B+2;
        for(int i = 0;i < A;i ++) {
            double tmp = B-A + 2*(A-i-1) + 1 + p[i]*(B+1);
            if(tmp < res) res = tmp;
        }
        
        printf("Case #%d: %6lf\n", cas, res);
    }
    return 0;
}
