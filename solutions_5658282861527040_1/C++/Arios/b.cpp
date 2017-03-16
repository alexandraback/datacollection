#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define N 31

vector < int > va, vb, vk;

void init(vector < int >&v, int x) {
    v.clear();
    for (int i = 0; i < N; ++i, x >>= 1)
        v.push_back(x & 1);
    reverse(v.begin(), v.end());
}

void read() {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    init(va, a);
    init(vb, b);
    init(vk, k);
}

LL dp[N + 2][2][2][2];

LL solve() {
    read();
    memset(dp, 0, sizeof(dp));
    dp[0][1][1][1] = 1;
    for (int i = 0; i < N; ++i)
        for (int sa = 0; sa < 2; ++sa)
            for (int sb = 0; sb < 2; ++sb)
                for (int sk = 0; sk < 2; ++sk)
                    if (dp[i][sa][sb][sk]) {
                        for (int fa = 0; fa < 2; ++fa)
                            for (int fb = 0; fb < 2; ++fb) {
                                int fk = fa & fb;
                                if (1 == sa && fa > va[i]) continue;
                                if (1 == sb && fb > vb[i]) continue;
                                if (1 == sk && fk > vk[i]) continue;
                                int ga = 1 == sa && fa == va[i];
                                int gb = 1 == sb && fb == vb[i];
                                int gk = 1 == sk && fk == vk[i];
                                dp[i + 1][ga][gb][gk] += dp[i][sa][sb][sk];
                            }
                    }
    return dp[N][0][0][0];
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: %lld\n", ++cas, solve());
    }
    return 0;
}
