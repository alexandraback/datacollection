#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100+5;
int c, d, v, a[N];

int solve() {
    sort(a, a+d);
    int ret = 0;
    ll cur = 0;
    for(int i = 0;i < d; i++) {
        if(i == 0 && a[i] == 1) {
            cur += 1ll*a[i]*c;
            continue;
        }
        if(cur+1 >= a[i]) {
            cur += 1ll*a[i]*c;
        } else {
            while(cur+1 < a[i]) {
                ret++;
                cur += (cur+1)*c;
            }
            cur += 1ll*a[i]*c;
        }
//        printf("i = %d ret = %d cur = %I64d\n", i, ret, cur);
        if(cur >= v)    break;
    }
    while(cur < v) {
        ret++; cur += (cur+1)*c;
    }
    return ret;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int t, cas = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &c, &d, &v);
        for(int i = 0;i < d; i++) {
            scanf("%d", &a[i]);
        }
        printf("Case #%d: %d\n", cas++, solve());
    }
    return 0;
}
