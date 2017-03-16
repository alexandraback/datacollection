#include <cstdio>
 
using namespace std;
 
typedef unsigned long long ull;
 
ull gcd(ull a, ull b)
{
    while (b) {
        ull t=a%b;
        a=b;
        b=t;
    }
    return a;
}
 
int main(void)
{
    int tot; scanf("%d", &tot);
    for (int t=1; t<=tot; t++) {
        printf("Case #%d: ", t);
        ull p, q; scanf("%llu/%llu", &p, &q);
        ull g=gcd(p, q);
        p/=g;
        q/=g;
        int bad=0;
        ull qq=q;
        while (qq>1) {
            if (qq%2) {
                printf("impossible\n");
                bad=1;
                break;
            }
            qq>>=1;
        }
        if (bad)
            continue;
        int i=1;
        ull pp=p;
        for ( ; i<=41; i++) {
            if (pp>=q)
                break;
            pp<<=1;
        }
        i--;
        i>40 ? printf("impossible\n") : printf("%d\n", i);
    }
}
