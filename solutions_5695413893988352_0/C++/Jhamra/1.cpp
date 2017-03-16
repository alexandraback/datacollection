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

char S[40],T[40];

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        scanf("%s %s",S+1,T+1);

        int n=strlen(S+1),bg;

        int x=1;

        for(;x<=n;x++)
        {
            if(S[x]==T[x])continue;
            else if(S[x]=='?'||T[x]=='?')continue;
            else break;
        }

        if(x>n)
        {
            for(int i=1;i<=n;i++)
            {
                if(S[i]==T[i]&&S[i]=='?')S[i]=T[i]='0';
                else if(S[i]=='?')S[i]=T[i];
                else if(T[i]=='?')T[i]=S[i];
            }
        }
        else if(x==1)
        {
            for(int i=x+1;i<=n;i++)
            {
                if(S[x]>T[x])
                {
                    if(S[i]=='?')S[i]='0';
                    if(T[i]=='?')T[i]='9';
                }
                else
                {
                    if(S[i]=='?')S[i]='9';
                    if(T[i]=='?')T[i]='0';
                }
            }
        }
        else
        {
            for(int i=1;i<=x-2;i++)
            {
                if(S[i]==T[i]&&S[i]=='?')S[i]=T[i]='0';
                else if(S[i]=='?')S[i]=T[i];
                else if(T[i]=='?')T[i]=S[i];
            }

            ll mn=LLONG_MAX,a,b;

            for(int i=0;i<=9;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    ll aa=0,bb=0;

                    if(S[x-1]=='?')aa=i;
                    else aa=S[x-1]-'0';

                    if(T[x-1]=='?')bb=j;
                    else bb=T[x-1]-'0';

                    aa=aa*10+S[x]-'0';
                    bb=bb*10+T[x]-'0';

                    for(int k=x+1;k<=n;k++)
                    {
                        if(aa>bb)
                        {
                            if(S[k]=='?')aa=aa*10;
                            else aa=aa*10+S[k]-'0';

                            if(T[k]=='?')bb=bb*10+9;
                            else bb=bb*10+T[k]-'0';

                        }
                        else
                        {
                            if(S[k]=='?')aa=aa*10+9;
                            else aa=aa*10+S[k]-'0';

                            if(T[k]=='?')bb=bb*10;
                            else bb=bb*10+T[k]-'0';
                        }
                    }

                    if(mn>abs(aa-bb))mn=abs(aa-bb),a=aa,b=bb;
                }
            }

            for(int i=n;i>=x-1;i--)
            {
                S[i]=a%10+'0';a/=10;
                T[i]=b%10+'0';b/=10;
            }
        }

        printf("Case #%d: %s %s\n",cases,S+1,T+1);
    }
}
