#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <utility>
#define SS 250000

using namespace std;

int r;
int n, x, y;
int ok, all;
int height[500000];

set< pair<int, int> > diam;

void brute(int n, int cx, int cy) {
    // r++;
    // printf("%d %d %d\n", n, cx, cy);
    // printf("... %d %d %d %d %d ...\n", height[-2 + SS], height[-1 +SS], height[SS], height[1 + SS], height[2 + SS]);
    // if ( r > 20 ) return ;
    if ( n == 0 ) {
        all++;
        if ( diam.find(make_pair(x, y)) != diam.end() ) ok++;
        return ;
    }
    /* x = 0; y = height[0 + SS] + 1; */
    if ( cy == 0 ||
            (height[cx-1 + SS] >= cy &&
             height[cx+1 + SS] >= cy) ) {
        int t1, t2;
        t1 = height[cx - 1 + SS];
        t2 = height[cx + 1 + SS];
        height[cx + SS] += 2;
        height[cx-1 + SS] = height[cx + SS] - 1;
        height[cx+1 + SS] = height[cx + SS] - 1;
        diam.insert(make_pair(cx, cy));
        brute(n-1, 0, height[0 + SS] + 1);
        diam.erase(diam.find(make_pair(cx, cy)));
        height[cx + SS] -= 2;
        height[cx-1 + SS] = t1;
        height[cx+1 + SS] = t2;
    }
    else {
        if ( height[cx-1 + SS] < cy ) {
            brute(n, cx-1, height[cx-1 + SS] + 1);
        }
        if ( height[cx+1 + SS] < cy ) {
            brute(n, cx+1, height[cx+1 + SS] + 1);
        }
    }
    // printf("-- %d %d %d\n", n, cx, cy);
    // printf("... %d %d %d %d %d ...\n", height[-2 + SS], height[-1 +SS], height[SS], height[1 + SS], height[2 + SS]);
}
int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, t;

    scanf("%d", &T);

    for (t=1; t<=T; ++t) {
        scanf("%d %d %d", &n, &x, &y);

        memset(height, -1, sizeof(height));

        ok = 0; all = 0;
        brute(n, 0, height[0 + SS] + 1);

        printf("Case #%d: %.8lf\n", t, (double)ok/(double)all);
    }

    return 0;
}
