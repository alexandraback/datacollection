#include <cstdio>
#include <iostream>
#include <cstring>

#define rep(i, s, t) for (auto i = s; i <= t; ++i)

using namespace std;

int a[10001];
int sp[10001];
int tr;
int ans;
int E, R, N;

void dfs(int d, int left) {
    if (d >= N) {
        if (tr > ans) {
            ans = tr;
        }
        return;
    }
    for (int i = left; i >= 0; i--) {
        tr += a[d] * i;
        dfs(d+1, min(E, left - i + R));
        tr -= a[d] * i;
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for (int ca = 1;ca <= T ;ca++) {
        scanf("%d %d %d",&E,&R,&N);
        if (R > E) {
            R = E;
        }
        for (int i = 0 ;i<=N-1;i++) {
            scanf("%d",&a[i]);
        }
        memset(sp, 0, sizeof(sp));
        tr = 0;
        ans = 0;
        dfs(0, E);
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}