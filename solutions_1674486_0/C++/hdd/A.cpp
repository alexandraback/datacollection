#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 100;
vector<vector<int> > graphy;
vector<bool> flow;
vector<bool> visit;

int n;
void initial()
{
    scanf("%d",&n);
    graphy.assign(n+1,vector<int>());
    flow.assign(n+1,true);
    int x,y;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        for(int j = 0; j < x; j++)
        {
            scanf("%d",&y);
            graphy[i].push_back(y);
            flow[y] = false;
        }
    }
}

bool dfs(int x)
{
    if(visit[x]) return true;
    visit[x] = true;
    for(int i = 0,y; i < graphy[x].size(); i++)
    {
        y = graphy[x][i];
        if(dfs(y))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int cas,icas;
    scanf("%d",&cas);
    for(icas=1; icas<=cas; ++icas)
    {
        initial();
        bool mysolve=false;
        for(int i = 1; i <= n; i++)
        {
            if(flow[i])
            {
                visit.assign(n+1,false);
                if(dfs(i))
                {
                    mysolve=true;
                }
            }
        }
        if(mysolve) printf("Case #%d: Yes\n",icas);
        else printf("Case #%d: No\n",icas);
    }

}
