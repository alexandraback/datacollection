#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;

const int inf = 1000*1000*1000+1;

int C, D, V;
int a[105];

int f(int i, std::vector<bool> v) {
    bool done = true; for (int j = 0; j < sz(v); j++) if (!v[j]) { done = false; break; }
    if (done) return 0;
    int ret = inf;
    if (v[i]) ret = std::min(ret, f(i+1, v));
    for (int j = V; j >= i; j--) v[j] = (v[j] || v[j-i]);
    ret = std::min(ret, f(i+1, v)+1);
    return ret;
}

int main()
{
    int TestCases; scanf("%d", &TestCases);
    for (int testcase = 1; testcase <= TestCases; testcase++) {
        scanf("%d%d%d", &C, &D, &V);
        for (int d = 0; d < D; d++) scanf("%d", &a[d]);
        if (C > 1) continue;
        std::vector<bool> v(V+1); v[0] = true;
        for (int d = 0; d < D; d++) for (int i = V; i >= a[d]; i--) v[i] = (v[i] || v[i-a[d]]);
        int ans = f(1, v);
        printf("Case #%d: ", testcase);
        printf("%d", ans);
        printf("\n");
    }
}

