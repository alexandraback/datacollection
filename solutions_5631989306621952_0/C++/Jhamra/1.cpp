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

char S[1004],ans[2004];

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        for(int i=0;i<=2003;i++)ans[i]=0;

        gets(S+1);
        int n=strlen(S+1);

        int l=1002,r=1002;

        ans[1002]=S[1];

        for(int i=2;i<=n;i++)
        {
            if(S[i]>=ans[l])ans[--l]=S[i];
            else ans[++r]=S[i];
        }

        int ind=0;
        for(;ans[ind]==0;ind++);

        printf("Case #%d: %s\n",cases,ans+ind);
    }
}
