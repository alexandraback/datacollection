#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 30;
int c, d, v, a[N], now[N];
bool vv[N], val[N], coin[N];

bool check(int lim) {
    memset(vv, false, sizeof(vv));
    for(int i = 0; i <= v; i++)
        vv[i] = val[i];
    for(int i = 0; i < lim; i++)
        for(int j = v; j >= now[i]; j--)
            for(int k = 1; k <= c; k++)
                if(k*now[i] <= j && vv[j-k*now[i]])
                    vv[j] = true;
    for(int i = 0; i <= v; i++)
        if(!vv[i]) return false;
    return true;
}
bool dfs(int lim, int x) {
    if(lim == x) {
        return check(lim);
    }
    for(int i = 1; i <= v; i++) {
        if(!coin[i]) {
            now[x] = i;
            coin[i] = true;
            if(dfs(lim, x+1))
                return true;
            coin[i] = false;
        }
    }
    return false;
}
int main() {
   freopen("C-small-attempt0.in", "r", stdin);
   freopen("c-small.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &c, &d, &v);
        memset(val, false, sizeof(val));
        memset(coin, false, sizeof(coin));
        int pd = 0;
        for(int i = 0; i < d;  i++) {
            scanf("%d", a + pd);
            if(a[pd] <= v) {
                coin[a[pd]] = true;
                pd++;
            }
        }
        d = pd;
        val[0] = true;
        for(int i = 0; i < d; i++)
            for(int j = v; j >= a[i]; j--)
                for(int k = 1; k <= c; k++)
                    if(k*a[i] <= j && val[j-k*a[i]])
                        val[j] = true;
        bool flag = true;
        for(int i = 0; i <= v; i++)
            if(!val[i]) flag = false;
        if(flag) {
            printf("Case #%d: %d\n", cas, 0);
            continue;
        }
        for(int i = 1; i <= v-d; i++)
            if(dfs(i, 0)) {
                printf("Case #%d: %d\n", cas, i);
                break;
            }
    }
    return 0;
}
