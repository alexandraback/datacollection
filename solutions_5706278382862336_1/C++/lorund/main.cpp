#include <cstdio>

int T;
long long a, b;

long long gcd(long long a, long long b){
    if (!b)
        return a;
    return gcd(b, a%b);
}

bool ispow(long long x){
    while (x && x%2==0)
        x /= 2;
    return x==1;
}

long long solve(long long a, long long b)
{
    long long cmmdc = gcd(a,b), sol=0;

    a /= cmmdc;
    b /= cmmdc;

    if (!a)
        return 0;
    if (!ispow(b))
        return 0;

    while (a<b/2){
        ++sol;
        b /= 2;
    }

    return sol+1;
}

int main()
{
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);

    scanf("%d", &T);
    for (int t=1; t<=T; ++t){
        scanf("%I64d/%I64d", &a, &b);

        if (!solve(a,b)){
            printf("Case #%d: impossible\n", t);
        }
        else{
            printf("Case #%d: %I64d\n", t, solve(a, b));
        }
    }
    return 0;
}
