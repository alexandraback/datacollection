#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T;
int C,D,V;
int d[6];
bool f[50],p[50];
int g[7];
bool ok;
void dfs(int depth, int L, int last)
{
    if (ok) {
        return;
    }
    if(depth == 0) {
        memset(p,0,sizeof(p));
        for (int i=0; i<(1<<L); i++) {
            int val = 0;
            for (int j=0; j<L; j++)
                if (i&(1<<j)) {
                    val += g[j];
                }
            for (int j = 0; j < V; j++)
                if (f[j]&&j+val<=V) {
                    p[j+val] = 1;
                }
        }
        ok = 1;
        for (int i=1; i<=V; i++)
            if (!f[i] && !p[i]) {
                ok = 0;
                break;
            }
        return;
    }
    for (int i = last+1; i<=V; i++) {
        bool flag = 0;
        for (int j=0; j<D; j++)
            if (i==d[j]) {
                flag = 1;
                break;
            }
        if (flag) continue;
        if (ok) {
            return;
        }
        g[depth - 1] = i;
        dfs(depth-1, L, i);

    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w",stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <=T; cas ++) {
        scanf("%d%d%d",&C,&D,&V);
        for (int i=0; i<D; i++) {
            scanf("%d",&d[i]);
        }
        memset(f,0,sizeof(f));
        for (int i=0; i<(1<<D); i++) {
            int val = 0;
            for (int j=0; j<D; j++)
                if (i&(1<<j)) {
                    val += d[j];
                }
            if (val <= V) {
                f[val] = 1;
            }
        }
        ok = 0;
        int ans=111111;
        for (int i=0; i<7; i++) {
            dfs(i, i, 0);
            if (ok) {
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
