#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, a[101][101];

void solve() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int h = a[i][j];
            bool vRow = true, vCol = true;
            for (int k = 0; k < m; ++k)
                if (a[i][k] > h) {
                    vCol = false;
                }
            for (int k = 0; k < n; ++k)
                if (a[k][j] > h) {
                    vRow = false;
                }
            if (!vRow && !vCol) {
                printf("NO\n");
                return;
            }
        }
    printf("YES\n");
    return;
}

int main() {
    int numOfCases;
    scanf("%d", &numOfCases);
    for (int caseNo = 1; caseNo <= numOfCases; ++caseNo) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
        printf("Case #%d: ", caseNo);
        solve();
    }
    return 0;
}
