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

int main()
{
    freopen ("D-small-attempt2.in","r",stdin);
    freopen ("D-small-attempt2.out","w",stdout);

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        int flag=0,x=getnum(),r=getnum(),c=getnum();

        if((r*c)%x!=0)flag=1;
        if(x!=2&&x%2==0&&(c==x/2||r==x/2))flag=1;
        for(int i=1;i<=x;i++)
        {
            int j=x+1-i;
            if(j<i)break;
            if(i>c&&j>c)flag=1;
            if(i>r&&j>r)flag=1;
            if(i>r&&i>c)flag=1;
            if(j>c&&j>r)flag=1;

        }
        printf("Case #%d: ",cases);
        if(flag)puts("RICHARD");
        else puts("GABRIEL");
    }
}
