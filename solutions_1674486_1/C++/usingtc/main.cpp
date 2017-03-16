#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

typedef long long i64d;

const int maxN = 1024;
const int maxE = 1024 * 1024;

struct node
{
    int v;
    node *nxt;
};
node *G[maxN]; int N;
node E[maxE]; int nE;

void init()
{
    nE = 0;
    memset(G, 0, sizeof(G));
}

void add(int u, int v)
{
    E[nE].v = v; E[nE].nxt = G[u];
    G[u] = &E[nE++];
}

int dist[maxN];

void bfs(int s)
{
    static int Q[maxN]; int Qs, Qt;
    Qs = Qt = 0;

    Q[Qt++] = s; dist[s] = 0;
    while( Qs != Qt ) {
        int u = Q[Qs++];
        if( Qs == maxN ) Qs = 0;

        for(node *e = G[u]; e; e = e->nxt) {
            if( dist[e->v] == -1 ) {
                dist[e->v] = dist[u] + 1;
                Q[Qt++] = e->v;
                if( Qt == maxN ) Qt = 0;
            }
        }
    }
}

int path[maxN];
bool vst[maxN];

void dfs(int u)
{
    vst[u] = 1;
    for(node *e = G[u]; e; e = e->nxt) {
        path[e->v] ++;
        if( vst[e->v] ) continue;
        dfs(e->v);
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int idx = 0, nt; scanf("%d", &nt);
    while( (nt --) > 0 ) {
        scanf("%d", &N); int M;
        init();
        for(int i = 1; i <= N; ++i) {
            scanf("%d", &M); int v;
            for(int j = 0; j < M; ++j) {
                scanf("%d", &v);
                add(i, v);
            }
        }
/*
        for(int i = 1; i <= N; i++) {
            printf("[%d]", i);
            for(node *e = G[i]; e; e = e->nxt)
                printf(" ---> [%d]", e->v);
            printf("\n");
        }*/

        bool ok = 0;
        for(int i = 1; i <= N && !ok; i++) {
            //memset(dist, -1, sizeof(dist));
            //bfs(i);
            memset(vst, 0, sizeof(vst));
            memset(path, 0, sizeof(path));
            dfs(i);
            for(int j = 1; j <= N; j++)
                if( path[j] > 1 )
                    { ok = 1; break; }/*
            if( i == 1 ) {
                for(int j = 1; j <= N; j++)
                    printf("%d ", path[j]);
                printf("\n");
            }*/
        }

        printf("Case #%d: %s\n", ++idx, ok ? "Yes" : "No");
    }
    return 0;
}
