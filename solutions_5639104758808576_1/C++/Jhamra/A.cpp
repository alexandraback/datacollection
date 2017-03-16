#include<bits/stdc++.h>
#define ll long long

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

char S[1006];
int A[1006];

int main()
{
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.out","w",stdout);

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        int n=getnum(),ans=0;
        gets(S);

        A[0]=S[0]-'0';

        for(int i=1;i<=n;i++)
        {
            int x=S[i]-'0',xx=0;

            if(A[i-1]<i)ans+=i-A[i-1],A[i]=i+x;
            else A[i]=A[i-1]+x;
        }
        printf("Case #%d: %d\n",cases,ans);
    }
}
