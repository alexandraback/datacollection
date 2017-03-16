#include<stdio.h>
#include<algorithm>
using namespace std;
#define HEI 2500
#define N 50
int n;
int mvpn, mxpn;
int mvp[N], mxp[N];
int d[2*N][N];
int cnt[HEI+1];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T, t = 1;
    for(scanf("%d", &T); (T--); ++t) {
        scanf("%d", &n); mvpn = mxpn = 0;
        int mv = HEI+1, mx = 0;
        for(int i = 0; i <= HEI; ++i) cnt[i] = 0;
        for(int i = 0; i < 2*n-1; ++i) for(int j = 0; j < n; ++j) scanf("%d", &d[i][j]);
        for(int i = 0; i < 2*n-1; ++i) mv = min(mv, d[i][0]);
        for(int i = 0; i < 2*n-1; ++i) mx = max(mx, d[i][n-1]);
        for(int i = 0; i < 2*n-1; ++i) if(d[i][0] == mv) mvp[mvpn++] = i;
        for(int i = 0; i < 2*n-1; ++i) if(d[i][n-1] == mx) mxp[mxpn++] = i;
        for(int i = 0; i < 2*n-1; ++i) for(int j = 0; j < n; ++j) cnt[d[i][j]] ++;
        printf("Case #%d: ", t);
        for(int i = 0; i <= HEI; ++i) if(cnt[i]&1) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
