/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
#define INF 0x7fffffff
const double eqs=1e-8;
LL gcd(LL a,LL b)
{
    LL temp;
    while(b)
    {
        temp=a;
        a=b;
        b=temp%b;
    }
    return a;
}
int main()
{
    int t,cnt=0;
    freopen("A-small-attempt1.in" , "r" , stdin);
    freopen("A-small-attempt1.out" , "w" , stdout);
    scanf("%d",&t);
    while(t--)
    {
        LL p,q;
        scanf("%lld/%lld",&p,&q);
        LL d=gcd(p,q);
        p/=d,q/=d;
        int flag=0;
        LL t=2;
        for(int i=1;i<=40;i++)
        {
            if(q<t)
                break;
            if(q%t!=0)
            {
                flag=1;
                break;
            }
            t*=2;
        }
        printf("Case #%d: ",++cnt);
        if(flag==1)
        {
            printf("impossible\n");
            continue;
        }
        int ans=0;
        t=2;
        if(p==q)
        {
            ans=0;
        }
        else
        {
            for(ans=1;;ans++)
            {
                if(t*p>=q)
                    break;
                t*=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
