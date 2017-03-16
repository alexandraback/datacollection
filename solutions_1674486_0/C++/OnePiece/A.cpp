#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int vis[1200],M[1200][1200];
int n,OK;
int dfs(int cur)
{
    for(int i=1; i<=n; i++)
        if(M[cur][i]&&!vis[i])
        {
            vis[i]=1;
            dfs(i);
        }
        else if(M[cur][i]&&vis[i])
        {
            OK=1;
        }
}
int main()
{
    int T,id=1;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("2.txt","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(M,0,sizeof(M));
        for(int i=1; i<=n; i++)
        {
            int a;
            cin>>a;
            for(int j=0;j<a;j++)
            {
                int y;
                cin>>y;
                M[y][i]=1;
            }
        }
        OK=0;
        for(int i=1; i<=n&&!OK; i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i);
        }
        cout<<"Case #"<<id++<<": ";
        if(OK)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
