#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
vector<int> v[1010];

int num[1010];
int n;
bool vis[1010];

bool gao(int x)
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
    }

    vis[x]=true;
    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int f=q.front();
        q.pop();

        for(int i=0;i<v[f].size();i++)
        {
            if(vis[v[f][i]])
            {
                return true;
            }
            vis[v[f][i]]=true;
            q.push(v[f][i]);
        }
    }
    return false;
}
int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);

    int t;
    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {

        scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            num[i]=0;
        }

        for(int i=1;i<=n;i++)
        {
            int m;
            v[i].clear();
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                v[i].push_back(tmp);
                num[tmp]++;
            }
        }

        bool flag=false;
        for(int i=1;i<=n&&!flag;i++)
        {
            if(num[i]==0)
            {
                flag=gao(i);
            }
        }

        cout<<"Case #"<<ti<<": ";

        if(flag)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
