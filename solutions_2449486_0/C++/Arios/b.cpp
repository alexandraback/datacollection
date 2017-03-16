#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define N 105

int n, m;
int a[N][N];

bool solve() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            bool flag;
            flag = true;
            for (int p = 0; p < n && flag; ++p)
                if (a[p][j] > a[i][j])
                    flag = false;
            if (flag)
                continue;
            flag = true;
            for (int q = 0; q < m && flag; ++q)
                if (a[i][q] > a[i][j])
                    flag = false;
            if (!flag)
                return false;
        }
    return true;
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
        printf("Case #%d: %s\n", ++cas, solve() ? "YES" : "NO");
    }
    return 0;
}
