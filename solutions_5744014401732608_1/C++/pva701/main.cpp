#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long ll;

void solveTest() {
    int n;
    ll m;
    cin >> n >> m;
    ll tot = (1LL<<(n-2));
    if (tot < m) {
        printf("IMPOSSIBLE\n");
        return;
    }

    bool a[55][55] = {0};

    for (int i = 1; i + 1 < n; ++i)
        for (int j = i + 1; j < n; ++j)
            a[i][j] = true;

    if (m == tot) {
        --m;
        a[0][n - 1] = true;
    }

    for (int i = n - 2; i >= 1; --i, m >>= 1)
        if (m&1)
            a[0][i] = true;
    printf("POSSIBLE\n");
    for (int i = 0; i < n; ++i, printf("\n"))
        for (int j = 0; j < n; ++j)
            printf("%d", a[i][j]);
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solveTest();
    }
    return 0;
}

