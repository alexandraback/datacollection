#include <bits/stdc++.h>

using namespace std;
bool g[7][7]; ///change for large
int vis[7];
bool loop = true;

bool cycle(int cur, int b) {
    /*
    printf("ah\n");
    printf("VIS, @ %d: ", cur);
    for(int i=0; i<b; ++i) {
        printf("%d ", vis[i]);
    }
    printf("\n");
    */
    vis[cur] = 1;
    for (int i=0; i<b; ++i) {
        if (i == cur || g[cur][i] == false) {
            continue;
        }
        if (vis[i] == 0) {
            if(cycle(i, b)) return true;
        }
        else if (vis[i] == 1) {
            return true;
        }
    }
    vis[cur] = 2;
    return false;
}

long long dfs(int cur, int b) { ///assuming no cycles so no vis[] needed
    if (cur == b-1) return 1;

    long long sum=0;
    for (int i=0; i<b; ++i) {
        if (i == cur || g[cur][i] == false) continue;
        sum += dfs(i, b);
    }
    return sum;
}

int main()
{
    freopen("out", "w", stdout);
    int t;
    cin>>t;
    for (int _=1; _<=t; ++_) {
        int b; long long m;
        cin>>b>>m;
        bool possible = false;
        printf("Case #%d: ", _);
        long long state;
        for (state=0ll; state<1ll<<(b*(4)); ++state) {
            //printf("state is %lld\n", state);
            for (int i=0; i<b-1; ++i) {
                for (int j=0; j<b; ++j) {
                    if (state & 1<<(i*b+j)) {
                        g[i][j] = true;
                    } else {
                        g[i][j] = false; ///reset memory
                    }
                }
            }
            memset(vis, 0, sizeof(vis)); ///reset memory
            if (cycle(0, b)) {
                //printf("cycle\n\n");
                continue;
            }
            if (dfs(0, b) == m) {
                possible = true;
                printf("POSSIBLE\n");
                for (int i=0; i<b; ++i) {
                    for (int j=0; j<b; ++j) {
                        printf("%d", (int)g[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
        }
        if (!possible) {
            printf("IMPOSSIBLE\n");
        }
    }
}
