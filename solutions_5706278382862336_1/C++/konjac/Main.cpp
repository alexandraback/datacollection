#include <stdio.h>

long long gcd(long long a, long long b) {
    return (b==0)?a:gcd(b,a%b);
}

int main() {
    int bf;
    scanf("%d", &bf);
    for (int bt = 0; bt < bf; bt++) {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        long long d=gcd(a,b);
        a/=d;b/=d;
        int ans=0;
        while (a<b){
            if (b%2!=0){
                ans=-1;
                break;
            }
            b/=2;
            ++ans;
        }
        while (b!=1){
            if (b%2!=0){
                ans=-1;
                break;
            }
            b/=2;
        }
        if (ans==-1 || ans==0) printf("Case #%d: impossible\n", bt+1); else
            printf("Case #%d: %d\n", bt+1, ans);
    }
    return 0;
}
