#include<bits/stdc++.h>
using namespace std;
typedef long long int i64;
i64 gcd(i64 a,i64 b) {
if (a%b==0) return b; else return gcd(b,a%b);
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    for(int t=1;t<=tt;t++)
    {
        i64 p,q;
        scanf("%lld/%lld",&p,&q);
        i64 g = gcd(p,q);
        p=p/g;
        q=q/g;
        i64 age=0;
        bool f=true;
        double x = log2(q);
        double a = x-i64(x);
        if(a!=0)f=false;
        while(p<q && f && age<41)
        {
            if(!(q&1))
            {
                q=q/2;
                age++;
            }
            else
            {
                f=false;
                break;
            }
        }
        if(f && age<41)printf("Case #%d: %lld\n",t,age);
        else printf("Case #%d: impossible\n",t);
    }
    return 0;
}
