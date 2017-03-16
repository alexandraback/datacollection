#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include<queue>
#include<cstring>
#include<utility>
#include<cstdio>
using namespace std;
int dfs(int u,int visited[], int &fl, vector<vector<int> >adj,int par[])
{
   // cout<<"in dfs"<<u<<"\n";
    visited[u]=1;

    for(int i=0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]] && adj[u][i]!=par[u])
        {
            fl=1;
           // cout<<adj[u].size()<<"\n";
            //cout<<"cycle at"<<u<<" "<<adj[u][i]<<" "<<i<<"\n";
            return 0;
        }
        if(visited[adj[u][i]]==0)
        {
            par[adj[u][i]]=u;
            dfs(adj[u][i],visited,fl,adj,par);
        }
    }

}

int main()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++)
    {
        int m,n;
        scanf("%d",&n);
        vector<vector<int> >adj(n);
        for(int y=0;y<n;y++)
        {
            //vector<int>tmp;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int x;
                scanf("%d",&x);
                //tmp.push_back(x);
                adj[y].push_back(x-1);
               // adj[x-1].push_back(y);

            }
            //adj.push_back(tmp);
        }

        //cout<<"hi";
        int fl=0;
        for(int i=0;i<n;i++)
        {
            int visited[n];
            int par[n];
            memset(visited,0,sizeof(visited));
            memset(par,-1,sizeof(par));
            //if(visited[i]==0)
            dfs(i,visited,fl,adj,par);
            if(fl==1)break;
        }

        if(fl==1)cout<<"Case #"<<q+1<<": Yes\n";
        else cout<<"Case #"<<q+1<<": No\n";
    }


}
