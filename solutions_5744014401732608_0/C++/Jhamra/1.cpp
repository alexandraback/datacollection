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

int M[60][60];

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        for(int i=1;i<=55;i++)for(int j=1;j<=55;j++)M[i][j]=0;

        ll n=getnum(),k=getnum();

        printf("Case #%d:",cases);

        ll mx=1LL<<(n-2);

        if(mx<k){puts(" IMPOSSIBLE");continue;}

        puts(" POSSIBLE");

        if(n==2)
        {
            puts("01");
            puts("00");
            continue;
        }

        for(ll i=0;i<=63;i++)
        {
            ll p=1LL<<i;

            if(k&p)
            {
                ll j=i+2;
                for(int a=1;a<j;a++)
                {
                    for(int b=a+1;b<=j;b++)
                    {
                        M[a][b]=1;
                    }
                }
                if(j<n)M[j][n]=1;
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)putchar(M[i][j]+'0');
            puts("");
        }
    }
}
