#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int t, T, N, bff[1005], fa[1005][2], bc; // cnt -> count 4 lovers' path
bool vis[1005];

void solve() {
    int i, prev, nxt, cnt, candi;
    memset(fa,0,sizeof(fa));
    bc = 0;
    for ( i = 1 ; i <= N ; ++i  ) {
        cnt = 2; prev = i; nxt = bff[i];
        memset(vis,0,sizeof(vis)); vis[i] = true;
        while(1) {
            if ( bff[nxt] == prev ) {
                int minn = min(nxt,prev);
                if ( prev < nxt ) {
                    fa[minn][0] = max(fa[minn][0],cnt);
                }
                else {
                    fa[minn][1] = max(fa[minn][1],cnt);
                }
                break;
            }
            if ( bff[nxt] == i ) {
                bc = max(bc,cnt);
                break;
            }
            if ( vis[nxt] == true ) break;
            cnt++;
            vis[nxt] = true;
            prev = nxt; nxt = bff[nxt];
        }
    }
    for ( candi = 0, i = 1 ; i <= N ; ++i ) {
        candi = candi + fa[i][0] + fa[i][1];
        if ( fa[i][0] != 0 && fa[i][1] != 0 ) candi -= 2;
    }
    //printf("%d %d\n",candi,bc);
    printf("Case #%d: %d\n",t,max(candi,bc));

}

int main() {
    freopen("C-Large.in","r",stdin);
    freopen("C-Large.out","w",stdout);
    int i;
    scanf("%d",&T);
    for ( t = 1 ; t <= T ; ++t ) {
        scanf("%d",&N);
        for ( i = 1 ; i <= N ; ++i ) {
            scanf("%d",&bff[i]);
        }
        solve();
    }
    return 0;
}
