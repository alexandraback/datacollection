#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second

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

int A[1000008];

int rev(int x)
{
    if(x%10==0)return x;
    int y=0;
    for(;x>0;x/=10)
    {
        y=y*10+(x%10);
    }
    return y;
}

int main()
{
    A[1]=1;
    for(int i=2;i<=1e6;i++)A[i]=1e9;
    for(int i=2;i<=1e6;i++)
    {
        A[i]=min(A[i-1]+1,A[rev(i)]+1);
    }
    freopen ("A-small-attempt0.in","r",stdin);
    freopen ("A-small-attempt0.out","w",stdout);

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        ll x=getnum();
        printf("Case #%d: %d\n",cases,A[x]);
    }
}
