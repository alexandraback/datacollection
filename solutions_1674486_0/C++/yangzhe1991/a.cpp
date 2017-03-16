#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


vector<int> g[2000];
int visit[2000];
int bb;
void dfs(int p)
{
    //printf("p%d vp%d size%d\n",p,visit[p],g[p].size());
    if(bb)return;
    if(visit[p]>=2){bb=1;return;}
    for(int i=0;i<g[p].size();i++)
    {
        //if(g[p][i]==0)continue;
        int t=g[p][i];
        //g[p][i]=0;
        visit[t]++;
        dfs(t);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        memset(visit,0,sizeof(visit));
        int n;
        cin>>n;
        bb=0;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            int m;
            cin>>m;
            while(m--)
            {
                int t;
                cin>>t;
                g[i].push_back(t);
            }
        }
        for(int i=1;i<=n;i++)
        {
            //if(visit[i])continue;
            //visit[i]++;
            memset(visit,0,sizeof(visit));
            dfs(i);
        }
        printf("Case #%d: ",tt);
        if(bb)printf("Yes\n");
        else printf("No\n");

    }

    return 0;
}
