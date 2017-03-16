#include <stdio.h>
#define MAX 1001

int graph[MAX][MAX], in[MAX], visited[MAX];

int has_diamond(int x, int n) {
    int i;
    if(visited[x])
        return 1;

    visited[x] = 1;

    for(i = 1; i <= n; i++) {
        if(graph[x][i]) {
            if(has_diamond(i, n)) {
                break;
            }
        }
    }

    return i <= n;
}

int main() {
    int t, T, n, m, i, j, last, x;
    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        scanf("%d", &n);

        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                graph[i][j] = 0;
            }
            in[i] = 0;
        }

        for(i = 1; i <= n; i++) {
            scanf("%d", &in[i]);
            for(j = 0; j < in[i]; j++) {
                scanf("%d", &x);
                graph[x][i] = 1;
            }
        }

        for(i = 1; i <= n; i++) {
            if(!in[i]) {
                for(j = 1; j <= n; j++)
                    visited[j] = 0;
                if(has_diamond(i, n))
                    break;
            }
        }

        printf("Case #%d: %s\n", t, i <= n ? "Yes" : "No");
    }
    return 0;
}
