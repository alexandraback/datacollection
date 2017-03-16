#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct UnionSet {
    int ud[1000];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int n, m, K;
int f[32][32];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int solve() {
    const int r = n*m;
    const int rr = 1<<r;
    int ans = n*m;
    rep (b, rr) {
        rep (i, n) rep (j, m) {
            f[i][j] = (b>>(i*m+j)) & 1;
        }
        us.init();
        rep (i, n) rep (j, m) if (f[i][j] == 0) {
            rep (d, 4) {
                const int ni = i + dx[d];
                const int nj = j + dy[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (f[ni][nj] == 0) us.set(i*m+j, ni*m+nj);
                }
                else {
                    us.set(i*m+j, n*m);
                }
            }
        }
        int c = 0;
        rep (i, n) rep (j, m) {
            if (!us.same(i*m+j, n*m)) c++;
        }
        if (c >= K) {
            int x = 0;
            rep (i, 30) if (b&(1<<i)) x++;
            ans = min(ans, x);
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf(" %d %d %d", &n, &m, &K);
        printf("Case #%d: %d\n", _q+1, solve());
    }
    return 0;
}
