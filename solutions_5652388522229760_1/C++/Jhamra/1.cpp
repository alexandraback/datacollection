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

bool done[11];

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        for(int i=0;i<=9;i++)done[i]=0;

        ll n=getnum(),i;

        printf("Case #%d: ",cases);
        if(n==0){puts("INSOMNIA");continue;}
        int flag=0;

        for(i=1;;i++)
        {
            ll x=n*i;
            while(x>0)
            {
                if(!done[x%10])
                {
                    flag++;
                    done[x%10]=1;
                }
                x/=10;
            }
            if(flag==10)break;
        }
        printf("%lld\n",n*i);
    }
}
