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

vector<int> V;
int A[104],Ps[100004];

int main()
{
    freopen ("C-small-attempt0.in","r",stdin);
    freopen ("C-small-attempt0.out","w",stdout);

    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        int ans=0,c=getnum(),d=getnum(),v=getnum();
        memset(Ps,0,sizeof(Ps));
        V.clear();

        for(int i=1;i<=d;i++)A[i]=getnum();

        V.push_back(0);

        for(int i=1;i<=d;i++)
        {
            int l=V.size();

            for(int j=0;j<l;j++)V.push_back(V[j]+A[i]);
        }
        for(int i=0;i<V.size();i++)Ps[V[i]]=1;
        for(int i=1;i<=v;i++)if(!Ps[i])ans++;

        printf("Case #%d: %d\n",cases,ans);
    }
}
