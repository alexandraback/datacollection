#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b)
{
    return b ? gcd(b, a%b) : a;
}
bool judge(LL x)
{
    while((x&1)==0)
    {
        x >>= 1;
    }
    return x==1;
}
int main()
{
//    freopen("A-large.in", "r", stdin);
//    freopen("A-large.out", "w", stdout);
    int t, kase=0;
    scanf("%d", &t);
    LL p, q;
    while(t--)
    {
        cin>>p;
        getchar();
        cin>>q;
        LL g = gcd(p, q);
        p /= g;
        q /= g;
        printf("Case #%d: ", ++kase);
        if(judge(q))
        {
            int ans = 0;
            while(p<q)
            {
                p *= 2;
                ans++;
            }
            if(ans>40)  printf("impossible\n");
            else    printf("%d\n", ans);
        }
        else    printf("impossible\n");
    }
    return 0;
}
