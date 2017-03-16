#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long LL;
const int N = 101013;
set<int> T;
set<int>::iterator it;
LL ans;
int v[N],h[N],lm[N];
int TT,sTT,n,E,R,e;
bool cmp1(const int i, const int j) {
    return v[i] < v[j] || v[i] == v[j] && i > j;
}
int main() {
    for (scanf("%d", &TT), sTT = TT; TT; --TT) {
        scanf("%d%d%d", &E, &R, &n);
        for (int i = 1; i <= n; ++i) scanf("%d", v + i);
        for (int i = 1; i <= n; ++i) h[i] = i;
        sort(h + 1, h + n + 1, cmp1);
        T.clear();
        for (int i = n; i; --i) {
            T.insert(h[i]);
            it  = T.upper_bound(h[i]);
            if (it != T.end()) lm[h[i]] = *it;
            else lm[h[i]] = 0;
        }
        e = E;
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (lm[i] && R * (LL)(lm[i] - i) < E) {
                LL t = E - R * (LL)(lm[i] - i);
                if (e > t) ans += (e - t) * (LL)v[i], e = t;
            } else ans += e * (LL)v[i], e = 0;
            e = min(e + R, E);
        }
        printf("Case #%d: %I64d\n", sTT - TT + 1, ans);
    }
    return 0;
}
