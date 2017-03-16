#include<cstdio>
#include<vector>
using namespace std;

vector<int> G[1001];
int col[1001];
bool diamond = false;

void dfs(int s)
{
    col[s] = 1;
    for(vector<int>::iterator it = G[s].begin(); it!=G[s].end(); it++)
    {
        if(col[*it] == 0)
        {
            dfs(*it);
        }
        else if(col[*it] == 2)
            diamond = true;
    }
    col[s] = 2;
}

int main()
{
    int z; scanf("%d", &z); int z1 = z;
    while(z--)
    {
        int n; scanf("%d", &n);
        diamond = false;
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            int k; scanf("%d", &k);
            while(k--)
            {
                int t; scanf("%d", &t);
                G[i].push_back(t);
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                col[j] = 0;
            dfs(i);
        }

        printf("Case #%d: ", z1-z);
        if(diamond) printf("Yes\n");
        else printf("No\n");
    }
}

