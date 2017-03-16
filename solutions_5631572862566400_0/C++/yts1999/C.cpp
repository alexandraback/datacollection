#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge {
    int y,next;
};

int cnt;
Edge e[1010];
int b[1010];
int f[1010];
bool v[1010];
int dis[1010];
int mx;

void addedge(int x,int y) {
    e[++cnt].y = y;
    e[cnt].next = b[x];
    b[x] = cnt;
}

void dfs(int x,int f) {
    for (int i = b[x]; i != 0; i = e[i].next)
        if (e[i].y != f) {
            dis[e[i].y] = dis[x] + 1;
            mx = max(mx,dis[e[i].y]);
            dfs(e[i].y,x);
        }
}

int main() {
    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ",t);
        cnt = 0;
        memset(b,0,sizeof(b));
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            scanf("%d",&f[i]);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(v,0,sizeof(v));
            int x = i,dis1 = 0;
            for (; ; x = f[x]) {
                if (v[x]) {
                    if (x == i)
                        ans = max(ans,dis1);
                    break;
                }
                dis1++;
                v[x] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
            addedge(f[i],i);
        int ans1 = 0;
        for (int i = 1; i <= n; i++)
            if (f[f[i]] == i) {
                memset(dis,0,sizeof(dis));
                mx = 1;
                dis[i] = 1;
                dfs(i,f[i]);
                ans1 += mx;
                memset(dis,0,sizeof(dis));
                mx = 1;
                dis[f[i]] = 1;
                dfs(f[i],i);
                ans1 += mx;
            }
        ans = max(ans,ans1 / 2);
        printf("%d\n",ans);
    }
    return 0;
}
