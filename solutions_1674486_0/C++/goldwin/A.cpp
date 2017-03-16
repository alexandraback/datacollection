#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 60

using namespace std;

int n;
vector<int> adjList[MAX];
int cnt[MAX];

bool bfs(int src)
{
    memset(cnt,0,sizeof(cnt));
    queue<int> q;
    q.push(src);
    cnt[src] = 1;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        EACH(adjList[front],it)
        {
            if(cnt[*it] == 0) q.push(*it);
            cnt[*it]++;
        }
    }
    FOR(i,0,n-1) if(cnt[i] > 1) return false;
    return true;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(ca,1,t)
    {
        scanf("%d",&n);
        FOR(i,0,n-1) adjList[i].clear();
        FOR(i,0,n-1)
        {
            int m;
            scanf("%d",&m);
            FOR(j,0,m-1) 
            {
                int x;
                scanf("%d",&x);
                adjList[x-1].push_back(i);
            }
        }
        bool ans = true;
        FOR(i,0,n-1)
        {
            ans = bfs(i);
            if(!ans) 
            {
                break;
            }
        }
        printf("Case #%d: %s\n",ca,(!ans)?"Yes":"No");
    }
    getchar();getchar();
    return 0;
}
