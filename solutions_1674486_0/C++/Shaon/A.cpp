#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[1010];
bool vis[1010];

bool dfs(int i)
{
    vis[i]=true;
    for (int j=0;j<v[i].size();++j)
    {
        if (vis[ v[i][j] ])
            return true;
        else if (dfs(v[i][j]))
            return true;
    }
    return false;
}


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    int cases;

    scanf("%d",&cases);
    for (int m=1;m<=cases;++m)
    {
        int node;
        scanf("%d",&node);
        for (int i=1;i<=node;++i)
        {
            v[i].clear();
            int temp;
            scanf("%d",&temp);

            for (int j=0;j<temp;++j)
            {
                int in;
                scanf("%d",&in);
                v[i].push_back(in);
            }
        }

        bool yes=false;
        for (int i=1;i<=node;++i)
        {
            for (int j=0;j<=node;++j)
                vis[j]=false;

            if (dfs(i))
            {
                yes=true;
                break;
            }
        }
        if (yes)
            printf("Case #%d: Yes\n",m);
        else
            printf("Case #%d: No\n",m);


    }
    return 0;



}
