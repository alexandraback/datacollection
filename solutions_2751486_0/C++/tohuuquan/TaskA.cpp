#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = (int)1E6 + 5;

char a[MAXN];
int s[MAXN], f[MAXN], n, v;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("EXAMPLE.OUT", "w", stdout);

    int nTests;
    scanf("%d", &nTests);
    for (int t = 1; t <= nTests; ++t) {
        scanf("%s", a + 1); n = strlen(a + 1);
        scanf("%d", &v);

        s[n + 1] = 0; f[n + 1] = n + 1;
        for (int i = n; i > 0; --i) {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                s[i] = 0;
            else
                s[i] = s[i + 1] + 1;
            if (s[i] >= v) f[i] = i + v - 1; else f[i] = n + 1;
            f[i] = min(f[i], f[i + 1]);
        }

        long long res = 0;
        for (int i = 1; i <= n; ++i)
            res += n - f[i] + 1;

        printf("Case #%d: ", t);
        cout << res;
        if (t < nTests) cout << endl;
    }
}
