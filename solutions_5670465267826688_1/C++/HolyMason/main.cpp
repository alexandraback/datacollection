#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const int N = 10005;
char s[N];
int pre[N], suf[N];
int tab[][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
};

inline int key(char ch) {
    if(ch == 'i') return 2;
    if(ch == 'j') return 3;
    return 4;
}

inline int mul(int x, int y) {
    int v = tab[abs(x) - 1][abs(y) - 1];
    if(x * y < 0) v *= -1;
    return v;
}

int cir[5];
bool vis[20], can[20];
int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        LL n, X;
        scanf("%I64d%I64d", &n, &X);
        --X;
        scanf("%s", s + 1);
        pre[0] = 1;
        for(int i = 1; i <= n; ++i) pre[i] = mul(pre[i - 1], key(s[i]));
        suf[n + 1] = 1;
        for(int i = n; i >= 1; --i) suf[i] = mul(key(s[i]), suf[i + 1]);
        cir[1] = pre[n];
        for(int i = 2; i <= 4; ++i) cir[i] = mul(cir[i - 1], pre[n]);
        cir[0] = cir[4];
        bool Find = 0;
        memset(vis, 0, sizeof(vis));
        memset(can, 0, sizeof(can));
        for(int i = 1; i <= n; ++i) can[pre[i] + 4] = 1;
        for(int i = 1; i <= n; ++i) {
            int v = pre[i];
            for(int j = 0; j < 4; ++j) if(mul(cir[j], v) == 4) {
                if(j > X) continue;
                int use = j;
                if(mul(suf[i + 1], cir[(X - j) % 4]) != 4) continue;
                use += (X - j) % 4;
                for(int k = -4; k <= 4; ++k) if(vis[k + 4]) {
                    if(mul(cir[j], k) == 2) Find = 1;
                }
                for(int k = -4; k <= 4; ++k) if(can[k + 4]) {
                    for(int d = 0; d < 4; ++d) {
                        if(mul(cir[d], k) != 2) continue;
                        int sum = use + (d >= j ? 4 : 0);
                        if(sum <= X) Find = 1;
                    }
                }
            }
            vis[pre[i] + 4] = 1;
        }
        printf("Case #%d: ", ca);
        puts(Find ? "YES" : "NO");
    }
    return 0;
}
