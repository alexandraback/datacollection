#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

//global constants
const int INF = 1<<29;
const double EPS = 1e-8;
typedef __int64 LL;
typedef struct Edge {
    int v;
    Edge *next;
} Edge;

//local constants
const int N = 1010;
int n;
int next[N];
bool in_grp[N];
int visit[N];
Edge edges[N];
int e;
Edge* adj[N];

int dfs_grp(int v, int dep) {
    visit[v] = 1;
    dep++;
    int ret = dep;
    for (Edge* p = adj[v]; p != NULL; p = p->next) {
        int t = p->v;
        if (visit[t]) continue;
        if (in_grp[t]) continue;
        int tmp = dfs_grp(t, dep);
        if (ret < tmp) ret = tmp;
    }
    return ret;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t, cas = 0;
    scanf(" %d ", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int v;
            scanf(" %d", &v);
            next[i] = v-1;
        }
        // find group nodes
        int grp = 0;
        for (int i = 0; i < n; ++i) in_grp[i] = 0;
        for (int i = 0; i < n; ++i)
            if (next[next[i]] == i) {
                in_grp[i] = in_grp[next[i]] = 1;
                ++grp;
            }
        // reverse graph
        e = 0;
        for (int i = 0; i < n; ++i) adj[i] = NULL;
        for (int i = 0; i < n; ++i) {
            edges[e].v = i;
            edges[e].next = adj[next[i]];
            adj[next[i]] = &edges[e++];
        }
        int grp_sum = 0;
        for (int i = 0; i < n; ++i) visit[i] = 0;
        for (int i = 0; i < n; ++i) if (!visit[i] && in_grp[i]) grp_sum += dfs_grp(i, 0);
//        printf("grp = %d grp_sum = %d\n", grp, grp_sum);
        int circle_sum = 0;
        for (int i = 0; i < n; ++i) visit[i] = 0;
        int rnd = 0;
        for (int i = 0; i < n; ++i) {
            if (visit[i]) continue;
            ++rnd;
            int pos = i;
            while (!visit[pos]) {
                visit[pos] = rnd;
                pos = next[pos];
            }
            if (visit[pos] == rnd) {
                int cnt = 1;
                int tmp = next[pos];
                while (tmp != pos) {
                    ++cnt;
                    tmp = next[tmp];
                }
                if (circle_sum < cnt) circle_sum = cnt;
            }
        }
        printf("Case #%d: %d\n", ++cas, max(grp_sum,circle_sum));
    }
    return 0;
}
