#include <cstdio>

int T;
int a, b;

int gcd(int a, int b){
    if (!b)
        return a;
    return gcd(b, a%b);
}

bool ispow(int x){
    while (x && x%2==0)
        x /= 2;
    return x==1;
}

int solve(int a, int b)
{
    int cmmdc = gcd(a,b), sol=0;

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
        scanf("%d/%d", &a, &b);

        if (!solve(a,b)){
            printf("Case #%d: impossible\n", t);
        }
        else{
            printf("Case #%d: %d\n", t, solve(a, b));
        }
    }
    return 0;
}
