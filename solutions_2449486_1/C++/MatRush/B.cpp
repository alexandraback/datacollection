#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 111;
const int INF = 0x3F3F3F3F;
int n, m;
int mat[MAXN][MAXN];
int main() {
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        scanf("%d %d", &n, &m);
        queue<int> x[101];
        queue<int> y[101];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
                x[mat[i][j]].push(i);
                y[mat[i][j]].push(j);
            }
        }
        bool flag = true;
        for (int num = 1; num <= 100; num++) {
            while (!x[num].empty()) {
                int i = x[num].front(); x[num].pop();
                int j = y[num].front(); y[num].pop();
                bool ok = false;
                bool tmp = true;
                for (int k = 0; k < m; k++) {
                    if (mat[i][k] > num) tmp = false;
                }
                ok |= tmp;
                tmp = true;
                for (int k = 0; k < n; k++) {
                    if (mat[k][j] > num) tmp = false;
                }
                ok |= tmp;
                flag &= ok;
            }
        }
        printf("Case #%d: ", T);
        puts(flag ? "YES" : "NO");
    }
}
