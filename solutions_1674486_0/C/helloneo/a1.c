#include <stdio.h>
#include <string.h>
int n;
int graph[1001][1001];
int main()
{
    int tc, cn;
    int i, j, k;
    int fl;
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d", &n);
        memset(graph, 0, sizeof(graph));
        for (i = 1; i <= n; i++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &j);
                graph[i][j]++;
            }
        }
        for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (graph[i][k] && graph[k][j]) {
                graph[i][j] += graph[i][k] * graph[k][j];
                if (graph[i][j] > 2)
                    graph[i][j] = 2;
            }
        }
        }
        }
        fl = 0;
        for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (graph[i][j] == 2) {
                fl = 1;
                goto X;
            }
        }
        }
X:
        if (fl)
            printf("Case #%d: Yes\n", cn);
        else
            printf("Case #%d: No\n", cn);
    }
    return 0;
}
