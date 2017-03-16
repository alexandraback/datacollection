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

vector<ll> V;

int main()
{
    //freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=1;

    for(int cases=1;cases<=tests;cases++)
    {
        printf("Case #1:\n");

        ll a=(1<<15)+1,ans=0;

        for(int i=0;ans<50;i++)
        {
            ll x=a+i*2;

            for(ll j=2;j<=10;j++)
            {
                ll sum=0,y=x;

                for(ll k=1;y>0;k*=j,y/=2)sum+=k*(y%2);
                for(ll k=2;k*k<=sum;k++)if(sum%k==0){V.pb(k);break;}
            }

            if(V.size()==9)
            {
                ans++;
                for(int j=1<<15;j>0;j/=2)
                {
                    if(j&x)putchar('1');
                    else putchar('0');
                }

                for(int j=0;j<9;j++)printf(" %lld",V[j]);
                puts("");
            }

            V.clear();
        }
    }
}
