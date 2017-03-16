#include<bits/stdc++.h>
using namespace std;

int sz;
int a[1000000];
int b[1000000];
int c[1000000];
int p1[1000000];
int p2[1000000];
int p3[1000000];
int e[1000000];
bool used[1000000];
int nx[1000000];
int lt[1000000];
int s,f,S,J,P,K;
int all;
int a1[101][101];
int a2[101][101];
int cnt[101][101];

int add(int x,int y,int z)
{
    ++sz;
    a[sz]=x;
    b[sz]=y;
    c[sz]=z;
    e[sz]=sz+1;
    nx[sz]=lt[x];
    lt[x]=sz;
    ++sz;
    a[sz]=y;
    b[sz]=x;
    c[sz]=0;
    e[sz]=sz-1;
    nx[sz]=lt[y];
    lt[y]=sz;
}

bool dfs(int x)
{
    if(used[x])
        return false;
    used[x]=1;
    if(x==f)
        return true;
    int i=lt[x];
    for(;i;i=nx[i])
        if(c[i])
        {
            int y=b[i];
            if(x>0 && x<=J*P && y>J*P && y<=J*P+P*S)
            {
                int xx=p1[x];
                int yy=p3[y];
                ///cout<<x<<' '<<y<<' '<<xx<<' '<<yy<<"\n";
                if(cnt[xx][yy]<K && dfs(y))
                {
                    c[i]--;
                    c[e[i]]++;
                    cnt[xx][yy]++;
                    return true;
                }
            }else
            if(y>0 && y<=J*P && x>J*P && x<=J*P+P*S)
            {
                int xx=p1[y];
                int yy=p3[x];
                if(cnt[xx][yy] && dfs(y))
                {
                    c[i]--;
                    c[e[i]]++;
                    cnt[xx][yy]--;
                    return true;
                }
            }
            else
            if(dfs(y))
            {
                c[i]--;
                c[e[i]]++;
                return true;
            }
        }
    return false;
}

void check(int x)
{
    int i=lt[x];
    for(;i;i=nx[i])
    {
        int to=b[i];
        if(to<x)
            continue;
        if(!c[i])
            cout<<p1[x]<<' '<<p2[x]<<' '<<p3[to]<<"\n";
    }
}

main()
{
    freopen("Csmall5.in","r",stdin);
    freopen("Csmall5.out","w",stdout);
    int t;
    cin>>t;
    for(int t1=1;t1<=t;t1++)
    {
        for(int i=0;i<=100000;i++)
        {
            nx[i]=0;
            lt[i]=0;
        }
        sz=0;
        all=0;
        cout<<"Case #"<<t1<<": ";
        cin>>J>>P>>S>>K;
        for(int i=1;i<=J;i++)
            for(int j=1;j<=P;j++)
            {
                a1[i][j]=++all;
                p1[all]=i;
                p2[all]=j;
                add(0,all,K);
            }
        for(int i=1;i<=P;i++)
            for(int j=1;j<=S;j++)
            {
                a2[i][j]=++all;
                p3[all]=j;
            }
        for(int i=1;i<=J;i++)
            for(int j=1;j<=S;j++)
                cnt[i][j]=0;
        s=0;
        f=all+1;
        for(int i=1;i<=P;i++)
            for(int j=1;j<=S;j++)
                add(a2[i][j],f,K);
        for(int i=1;i<=J;i++)
            for(int j=1;j<=P;j++)
                    for(int j1=1;j1<=S;j1++)
                    {
                        add(a1[i][j],a2[j][j1],1);
                    }
        int ans=0;
        for(;dfs(0);++ans)
        {
            for(int i=s;i<=f;i++)
                used[i]=0;
        }
        for(int i=s;i<=f;i++)
            used[i]=0;
        cout<<ans<<"\n";
        for(int i=1;i<=J;i++)
            for(int j=1;j<=P;j++)
                check(a1[i][j]);
    }
}
