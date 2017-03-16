#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define si(a) scanf("%d",&a)
#define f first
#define s second
#define mp(a,b) make_pair(a,b)
#define INF 2000000000

const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 2000000;

int n1, n2, edges, last[MAXN1], prv[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prv[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prv[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prv[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}

/*int main()
{
    int t;
    si(t);
    for(int ca=1;ca<=t;ca++)
        solve(ca);
    return 0;
}*/

char s1[35],s2[35];

void solve(int ca)
{
    int t,i,cntbam=0,cntdan=0;
    si(t);
    map<string,int> allbam,alldan;
    vector<pair<int,int> > edge;
    for(i=0;i<t;i++){
        scanf("%s%s",s1,s2);
        string str1=s1,str2=s2;
        if(allbam.find(str1)==allbam.end())
            allbam[str1]=cntbam++;
        if(alldan.find(str2)==alldan.end())
            alldan[str2]=cntdan++;
        edge.push_back(mp(allbam[str1],alldan[str2]));
    }
    init(cntbam,cntdan);
    for(i=0;i<t;i++)
        addEdge(edge[i].f,edge[i].s);
    printf("Case #%d: %d\n",ca,t-cntbam-cntdan+maxMatching());
    return ;
}

int main()
{
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-small-attempt0.out","w",stdout);
    int t;
    si(t);
    for(int ca=1;ca<=t;ca++)
        solve(ca);
    return 0;
}

