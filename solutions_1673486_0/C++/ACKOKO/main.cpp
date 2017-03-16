#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int A, B;
int N, n;
double p[100010];
double cur, curi;
double ans;

int main()
{
    scanf("%d", &N);
    for(int T = 1;T <= N;T++){
        printf("Case #%d: ", T);
        scanf("%d%d", &A, &B);
        for(int i = 1;i <= A;i++){
            scanf("%lf", &p[i]);
        }
        curi = 1.0;
        ans = B*1.0+2.0;
        if(ans > A+B+1.0){
            ans = A+B+1.0;
        }
        for(int i = 1;i <= A;i++){
            curi = curi*p[i];
            cur = curi*(A+B-2*i+1.0);
            cur += (1.0-curi)*(A+2*B-2*i+2);
            if(cur < ans){
                ans = cur;
            }
        }
        printf("%.6lf\n", ans);
    }
    return 0;
}
