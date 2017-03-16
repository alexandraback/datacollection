#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int viz[1001];
vector<int> ls[1001];
int N;

bool bfs(int i)
{
    viz[i] = 1;
    queue<int> Q;
    Q.push(i);
    while(!Q.empty())
    {
        int c = Q.front();
        Q.pop();
        for(int k = 0; k < ls[c].size(); k++)
        {
            if (viz[ls[c][k]] == 0)
            {
                viz[ls[c][k]] = 1;
                Q.push(ls[c][k]);
            }
            else
            {
                if(ls[c][k] != i)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int init()
{
    for(int i = 0; i <= N; i++)
    {
        viz[i] = 0;
    }
}

int initd()
{
    for(int i = 0; i <= N; i++)
    {
        ls[i].clear();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &N);
        initd();
        for(int i = 1; i <= N; i++)
        {
            int M;
            scanf("%d", &M);
            for(int j = 0; j < M; j++)
            {
                int x;
                scanf("%d", &x);
                ls[i].push_back(x);
            }
        }

        bool found = false;
        for(int i = 1; i <= N && !found; i++)
        {
            if (ls[i].size() >= 2)
            {
                init();
                found = bfs(i);
            }
        }
        printf("Case #%d: ", t);
        if(found)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
