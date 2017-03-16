#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second

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
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);


    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        int ans=0,r=getnum(),c=getnum(),w=getnum(),i;

        ans=(c/w)-1;

        if(c%w==0)ans+=w;
        else ans+=w+1;

        printf("Case #%d: %d\n",cases,ans);
    }
}
