#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<cstdio>
#include<set>
#include<map>
#include<cstdlib>
#include<cstring>
#include<stack>

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define ABS(a) (a>0?a:-a)

#define SZ(a) ((int)a.size())
#define PB(a) push_back(a)
#define ULL unsigned long long
#define LL long long
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,(int)(n-1))
#define printv(v) REP(i,SZ(v))printf("%d ",v[i]);

using namespace std;

bool bfs(int i,vector <int> adj[],int n)
{
    bool visited[n];
    memset(visited,false,sizeof(visited));
    queue <int> q;
    visited[i] = true;
    q.push(i);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        //cout<<node<<' ';
        REP(j,SZ(adj[node]))
        {
            int neigh = adj[node][j];

            if (!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
            }
            else
            return true;
        }

    }
    return false;

}

int main()
{

    freopen("alarge.in","r",stdin);
    freopen("alout.txt","w",stdout);
int t;
cin>>t;
FOR(test,1,t)
{
    int n;
    cin>>n;

    vector <int> adj[n];

    REP(i,n)
    {
        int m;
        cin>>m;
        REP(j,m)
        {
            int temp;
            cin>>temp;
            adj[i].PB(temp-1);
        }
    }
    bool flag = false;
    REP(i,n)
    {
        if (bfs(i,adj,n))
        {
            flag = true;
            break;
        }

    }
    printf("Case #%d: ",test);
    if (flag)
    {
        printf("Yes\n");
    }
    else
    printf("No\n");
}

return 0;
}
