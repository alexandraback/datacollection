#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>

#define MAXN 1005
using namespace std;

int N;
vector<int> adj[MAXN];
bool flag, visited[MAXN];


void trace(int now)
{
    //printf("now: %d\n", now);

    if(flag)
        return ;

    if(visited[now])
    {
        flag = true;
        return ;

    }else{
        visited[now] = true;
    }

    for(int i=0;i<adj[now].size();i++)
        trace( adj[now][i] );
}

void process(int case_number)
{
    scanf("%d", &N);

    for(int i=1;i<=N;i++)
    {
        int M, index;
        scanf("%d", &M);

        for(int j=0;j<M;j++)
        {
            scanf("%d", &index);
            adj[i].push_back(index);
        }
    }

    /*for(int i=1;i<=N;i++)
    {
        printf("V_%d:", i);
        for(int j=0;j<adj[i].size();j++)
            printf(" %d", adj[i][j]);
        putchar('\n');
    }*/

    flag = false;

    for(int i=1;i<=N;i++)
    {

        // Inital
        memset(visited, false, sizeof(visited));

        // Trace
        trace(i);

        if(flag)
            break;
    }

    printf("Case #%d: %s\n", case_number, flag?"Yes":"No");

    for(int i=1;i<=N;i++)
        adj[i].clear();
}

int main(int argc, char *argv[])
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int i=1;i<=T;i++)
        process(i);

	return 0;
}
