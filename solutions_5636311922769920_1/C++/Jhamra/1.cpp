#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 10000002
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}


int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        ll n=getnum(),c=getnum(),s=getnum();

        printf("Case #%d: ",cases);

        if(n==1)puts("1");
        else if(c==1)
        {
            if(s<n)puts("IMPOSSIBLE");
            else
            {
                for(int i=1;i<=n;i++)printf("%d ",i);
                puts("");
            }
        }
        else if(n==2)puts("2");
        else if(n==3)
        {
            if(s==1)puts("IMPOSSIBLE");
            else
            {
                ll x=1;
                for(;c--;x*=n);

                printf("2 %lld\n",x-1);
            }
        }
        else
        {
            if(s<n-2)puts("IMPOSSIBLE");
            else
            {
                ll x=1;
                for(;c--;x*=n);

                for(int i=2;i<=n-2;i++)printf("%d ",i);
                 printf("%lld\n",x-1);
            }
        }
    }
}
