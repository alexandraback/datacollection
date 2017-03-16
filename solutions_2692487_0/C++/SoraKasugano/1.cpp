#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100;
int solve() {
    int n, m, a[maxn];
    scanf("%d%d", &m, &n);
    for (int i = 0 ; i < n ; ++i) scanf("%d", a + i);
    if (m == 1) return n;
    sort(a, a + n);
    int v = n, c = 0;
    for (int i = 0 ; i < n ; ++i) {
        v = min(v, c + n - i);
        while (m <= a[i]) m += m - 1, ++c;
        m += a[i];
    }
    return min(v, c);
}
int main() {
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d" ,&t);
    for (int i = 1 ; i <= t ; ++i)
        printf("Case #%d: %d\n", i, solve());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
