#include <bits/stdc++.h>

using namespace std;

int a[1234567];

void solve() {
    int c, d, v;
    scanf("%d%d%d", &c, &d, &v);
    for (int i = 0; i < d; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + d);
    long long cur = 0;
    int z = 0;
    set<long long> have;
    for (int i = 0; i < d; i++) have.insert(a[i]);
    int ans = 0;
    while (cur < v) {
        while (z < d && a[z] <= cur + 1) {
            cur += (long long) a[z] * c;
            ++z;
        }
        if (cur >= v) break;
        bool found = false;
        for (long long j = cur + 1; j >= 1; j--) {
            if (have.find(j) != have.end()) continue;
            cur += (long long) c * j;
            have.insert(j);
            ++ans;
            found = true;
            break;
        }
        assert(found);
    }
    printf("%d\n", ans);
}

int main() {
    int tt;
    scanf("%d", &tt);
    for (int t = 1; t <= tt; t++) {
        printf("Case #%d: ", t);
        solve();
    }
}