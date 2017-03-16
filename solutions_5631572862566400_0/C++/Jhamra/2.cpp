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

int A[1003],done[1003],ok[1003],sz[1003];
vector<int> V[1003],Stack,cnt[1003];

int rdfs(int n,int grp)
{
    int mx=0;
    done[n]=grp;

    for(int i=0;i<V[n].size();i++)
    {
        mx=max(mx,rdfs(V[n][i],grp));
    }

    return mx+1;
}

void cycledfs(int n,int grp)
{
    if(ok[n])
    {
        while(Stack.size())
        {
            int x=Stack.back(),mx=0;
            Stack.pop_back();
            for(int i=0;i<V[x].size();i++)
            {
                int y=V[x][i];
                if(ok[y])continue;
                int r=rdfs(y,grp);
                mx=max(mx,r);
            }
            cnt[grp].pb(mx);
        }
        return;
    }
    ok[n]=1;
    sz[grp]++;
    Stack.pb(n);
    cycledfs(A[n],grp);
}

void dfs(int n,int grp)
{
    if(done[n])
    {
        cycledfs(n,grp);
        return;
    }
    done[n]=grp;
    dfs(A[n],grp);
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        for(int i=1;i<=1000;i++)
        {
            V[i].clear();
            cnt[i].clear();
            done[i]=ok[i]=sz[i]=0;
        }

        int n=getnum(),mx=0;

        for(int i=1;i<=n;i++)A[i]=getnum(),V[A[i]].pb(i);

        for(int i=1;i<=n;i++)if(!done[i])dfs(i,i);

        for(int i=1;i<=n;i++)if(sz[i]==2)mx+=sz[i]+cnt[i][0]+cnt[i][1];

        for(int i=1;i<=n;i++)
        {
            if(sz[i]>2)mx=max(mx,sz[i]);
        }

        printf("Case #%d: %d\n",cases,mx);
    }
}
