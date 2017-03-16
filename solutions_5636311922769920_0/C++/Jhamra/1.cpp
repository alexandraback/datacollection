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
        ll k=getnum(),c=getnum(),s=getnum(),x=1;

        printf("Case #%d: ",cases);

        if(k==1){puts("1");continue;}

        for(int i=1;i<=c;i++)x*=k;

        ll y=(x-1)/(k-1);

        for(ll a=1;a<=x;a+=y)printf("%lld ",a);
        puts("");
    }
}
