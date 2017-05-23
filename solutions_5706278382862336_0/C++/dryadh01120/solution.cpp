#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long P, Q, d, k;

long long gcd(long a, long b)
{
    return b==0 ? a : gcd(b, a%b);
}

int main(void)
{
    //freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-small-attempt1.out", "w", stdout);

    int t, i, cas=1, ans, flag, a;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld/%lld", &P, &Q);
        d=gcd(P, Q);
        P/=d; Q/=d;
        ans=(int)log2(Q);
        flag=0;
        for(i=1; ans-i>=0; ++i)
        {
            if((k=P-(long long)pow(2, ans-i))>=0)
            {
                P=k;
                if(flag==0) { a=i; flag=1; }
            }
        }


        printf("Case #%d: ", cas++);



        if(P>0 || P>Q || log2(Q)-(double)ans>1e-10)
        {
            printf("impossible\n");
        }
        else printf("%d\n", a);
    }


    return 0;
}
