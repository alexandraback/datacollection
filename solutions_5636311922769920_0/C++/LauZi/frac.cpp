#include <cstdio>
#include <vector>

using namespace std;

using ll = long long;

void jizz() {
    int k, c, s; scanf("%d%d%d", &k, &c, &s);

    if (s*c < k) {
        puts(" IMPOSSIBLE");
        return ;
    }

    vector<ll> ans;

    for (int idx = 0; idx < k; ) {
        ll acc = 0;
        for (int j = 0; j < c; ++j)
            acc = acc * k + (idx++ % k);
        ans.push_back(acc+1);
    }

    sort(begin(ans), end(ans));

    for (int i = 1, j = 0; (int)ans.size() < s; ++i) {
        if (ans[j] == i) {
            ++j;
        } else {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < s; ++i)
        printf(" %lld", ans[i]);
    putchar('\n');
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d:", t);
        jizz();
    }

    return 0;
}
