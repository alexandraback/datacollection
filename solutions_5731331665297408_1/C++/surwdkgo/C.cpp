#include <stdio.h>
#include <string.h>
int zip[100], adj[100][100], ans[100], cur, vis[100], sta[100], n, m;
int vis2[100];
void dfs2(int ii) {
    vis2[ii] = 1;
    for (int i=0; i<n; i++) {
        if (!vis2[i] && adj[ii][i]) dfs2(i);
    }
    return;
}
bool connected(int lay) {
    memset(vis2, 0, sizeof(vis2));
    for (int i=0; i<n; i++) {
        if (vis[i] > lay || vis[i] == -1) vis2[i] = 1;
    }
    for (int i=0; i<n; i++) {
        if (vis2[i] == 0) {
            dfs2(i);
            break;
        }
    }
    for (int i=0; i<n; i++) {
        if (vis2[i] == 0) return 0;
    }
    return 1;
}
void dfs(int ii, int lay) {
    vis[ii] = lay;
    sta[lay] = ii;
    ans[cur++] = ii;
    //int mii, miz = 1000000, ll = 0;
    //printf("%d-%d\n", ii, lay);
    while (1) {
    int mii, miz = 1000000, ll = 0;
        for (int l = lay; l >= 1; l--) {
            if (l != lay && ! connected(l)) break;
            for (int i=0; i<n; i++) {
                //printf("%d-%d-%d-%d-%d-%d\n", zip[i], l, i, vis[i], sta[l], adj[sta[l]][i]);
                if (adj[sta[l]][i] && !vis[i] && miz > zip[i]) {
                    miz = zip[i];
                    ll = l;
                    mii = i;
                }
            }
            if (ll < lay) break;
        }
        if (ll == lay) dfs(mii, lay+1);
        else break;
    }
    vis[ii] = -1;
    return;
}
int main() {
    int cas, mii;
    scanf("%d", &cas);
    for (int ii=0; ii < cas; ii++) {
        scanf("%d%d", &n, &m);
        int miz = 1000000;
        for(int i=0; i<n; i++) {
            scanf("%d", &zip[i]);
            if (zip[i] < miz) mii = i, miz = zip[i];
        }
        memset(adj, 0, sizeof(adj));
        for (int i=0; i<m; i++) {
            int st, ed;
            scanf("%d%d", &st, &ed);
            adj[st-1][ed-1] = 1;
            adj[ed-1][st-1] = 1;
        }
        cur = 0;
        memset(vis, 0, sizeof(vis));
        dfs(mii, 1);
        printf("Case #%d: ", ii+1);
        for (int i=0; i<n; i++) printf("%d", zip[ans[i]]);
        puts("");
    }
    return 0;
}
