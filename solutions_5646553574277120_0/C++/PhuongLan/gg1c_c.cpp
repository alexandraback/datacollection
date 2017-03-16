#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("C-small-attempt0.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif // ONLINE_JUDGE

    int nTest, a[1000], c, d, v, res;
    bool f[1000], stop;

    scanf("%d", &nTest);

    for (int iTest = 1; iTest <= nTest; ++iTest) {
        scanf("%d%d%d", &c, &d, &v);
        for (int i = 0; i < d; ++i) scanf("%d", &a[i]);

        stop = false;
        res = 0;
        while (!stop) {
            for (int i = 0; i <= v; ++i) f[i] = false;
            f[0] = true;
            for (int i = 0; i < d; ++i) {
                for (int j = v; j >= a[i]; --j) {
                    if (f[j - a[i]]) f[j] =true;
                }
            }
            stop = true;
            for (int i = 1; i <= v; ++i) {
                if (!f[i]) {
                    a[d] = i;
                    ++d; ++res;
                    sort(a, a+d);
                    stop = false;
                    break;
                }
            }
        }

        printf("Case #%d: %d\n", iTest, res);
    }

    return 0;
}
