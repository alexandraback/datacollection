#include <stdio.h>
#include <string.h>

const int N = 1010;
int in[N][N], inc[N], tinc[N];
int out[N][N], outc[N];
int Q[N];
int cnt[N][N];


bool find(int n) {
    int cq = 0;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i<= n; i++) {
        tinc[i] = inc[i];
        cnt[i][i] = 1;
        if (tinc[i] == 0) Q[cq++] = i;
    }
    int c = 0;
    while(cq < n) {
        int v = Q[c++];
        for (int i = 0; i < outc[v]; i++) {
            int k = out[v][i];
            tinc[k]--;
            if (tinc[k] == 0) Q[cq++]= k;
        }
    }
    for (int i = 0; i < n; i++) {
        int v = Q[i];
        for (int j = 0; j < i; j++) {
            cnt[Q[j]][v] = 0;
            for (int k = 0; k < inc[v]; k++) {
                int w = in[v][k];
                cnt[Q[j]][v] += cnt[Q[j]][w];
            }
            if (cnt[Q[j]][v] >= 2) return true;
        }
    }
    return false;
}

void solve(int cases) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        inc[i] = outc[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &outc[i]);
        for(int j = 0; j < outc[i]; j++) {
            scanf("%d", &out[i][j]);
            int k = out[i][j];
            in[k][inc[k]++] = i;
        }
        scanf("\n");
    }
    bool ok = find(n);
    if (ok) {
        printf("Case #%d: Yes\n", cases);
    } else {
        printf("Case #%d: No\n", cases);
    }
}

int main() {
    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}








// vim: set expandtab ts=4 sw=4 sts=4 tw=100: 
