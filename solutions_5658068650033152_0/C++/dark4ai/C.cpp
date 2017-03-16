#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

const int MAXNM = 21;

int n, m, k, mask, cnt, used;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

inline int gc(int y, int x) {
    return y * m + x;
}

inline int ith_bit(int i, int v) {
    return ((1 << i) & v) != 0;
}

inline void set_ith_bit_1(int i, int &v) {
    // n &= ((1 << (n * m)) - 1) ^ (1 << i);
    v |= (1 << i);
}

inline int is_valid(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

inline int get_cnt_1(int v) {
    int ans = 0;
    for(int i = 0; i < n * m; ++i) {
        ans += ith_bit(i, v);
    }
    return ans;
}

void dfs(int v) {
    if(ith_bit(v, used)) return;
    set_ith_bit_1(v, used);
    int cy = v / m, cx = v % m;
    for(int i = 0; i < 4; ++i) {
        int ny = cy + dy[i], nx = cx + dx[i];
        int u = gc(ny, nx);
        if(is_valid(ny, nx) && ith_bit(u, used) == 0) {
            dfs(u);
        }
    }
}

inline int get_k() {
    used = 0;
    for(int i = 0; i < n * m; ++i) {
        if(ith_bit(i, mask)) {
            set_ith_bit_1(i, used);
        }
    }
    for(int i = 0; i < n; ++i) {
        dfs(gc(i, 0));
        dfs(gc(i, m - 1));
    }
    for(int i = 0; i < m; ++i) {
        dfs(gc(0, i));
        dfs(gc(n - 1, i));
    }
    int ans = 0;
    for(int i = 0; i < n * m; ++i) {
        ans += (ith_bit(i, used) == 0 || ith_bit(i, mask));
    }
    return ans;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; ++t) {
        printf_debug("test %d\n", t);
        scanf("%d%d%d", &n, &m, &k);
        cnt = n * m;
        int ans = n * m;
        for(mask = 0; mask < (1 << cnt); ++mask) {
            int cur_k = get_k();
            if(cur_k == k) {
                ans = min(ans, get_cnt_1(mask));
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}