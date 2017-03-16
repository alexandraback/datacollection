#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
#define LL long long
using namespace std;
const int N=1000;
// int a[N];
int T,n,m;
// int fun(int n)
// {
    // return n*(n+1)/2;
// }
// void fen(int n)
// {
    // for(int i=2;;i++)
    // {
        // if(n==1)return ;
        // while(n%i==0)
        // {
            // cout<<" "<<i;
            // n/=i;
        // }
    // }
// }
LL gcd(LL a,LL b)
{
    LL x=b;
    while(b!=0)
    {
        x=a%b;
        a=b;
        b=x;
    }
    return a;
}
bool ok(LL x)
{
    while(x%2==0)
    {
        x/=2;
    }
    return x==1;
}
int main()
{
    freopen("ex.in","r",stdin);
    freopen("ex.out","w",stdout);
    cin>>T;
    int ncase=0;
    LL ep=1;
    for(int i=0;i<40;i++)
        ep*=2;
    while(T--)
    {
        printf("Case #%d: ",++ncase);
        LL p,q;
        cin>>p;
        scanf("%*c");
        cin>>q;
        LL x=gcd(q,p);
        q/=x;
        p/=x;
        if(q>ep||!ok(q))
        {
            printf("impossible\n");continue;
        }
        LL m=1;
        while(m*2<p)
        {
            m*=2;
        }
        LL n=q/m;
        LL num=0;
        while(n!=1)
        {
            num++;
            n>>=1;
        }
        cout<<num<<endl;
        // cout<<p<<" "<<q<<endl;
    }
    return 0;
}

