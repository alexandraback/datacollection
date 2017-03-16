#include <cstdio>
long long int gcd(long long int a, long long int b){
    return b?gcd(b,a%b):a;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    long long int i, maxg;
    long long int a, b, c, n = 1, gointo = 0;
    scanf("%lld", &i);
    for(long long int l = 0; l < i; l++){
        scanf("%lld/%lld", &a, &b);
        c = b / gcd(a, b);
        n = 0;
        gointo = 0;
        while(1){
            if (c == 1){
                gointo = 1;
                break;
            }
            if (c %2 != 0) {
                printf("Case #%lld: impossible\n", l+1);
                break;
            }
            c /= 2;
        }
        if (gointo){
            while (1){
                n++;
                a *= 2;
                if (a >= b) {
                    printf("Case #%lld: %lld\n", l+1, n);
                    break;
                }
            }
        }
    }
}
