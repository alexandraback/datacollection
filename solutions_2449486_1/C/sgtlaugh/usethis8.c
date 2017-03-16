#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 105
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

bool matrix[MAX][MAX];
int t, n, m, ar[MAX][MAX];

int main(){
    int line, i, j, k, l, d;

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        scanf("%d %d", &n, &m);

        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                scanf("%d", &ar[i][j]);
            }
        }

        clr(matrix);
        for (d = 1; d <= 100; d++){
            for (i = 0; i < n; i++){

                bool pass = true;
                for (j = 0; j < m; j++){
                    if (matrix[i][j]) continue;

                    if (ar[i][j] != d){
                        pass = false;
                        break;
                    }
                }

                if (pass){
                    for (j = 0; j < m; j++) matrix[i][j] = true;
                }
            }

            for (j = 0; j < m; j++){

                bool pass = true;
                for (i = 0; i < n; i++){
                    if (matrix[i][j]) continue;

                    if (ar[i][j] != d){
                        pass = false;
                        break;
                    }
                }

                if (pass){
                    for (i = 0; i < n; i++) matrix[i][j] = true;
                }
            }
        }

        bool res = true;
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                res &= matrix[i][j];
            }
        }

        if (res) printf("Case #%d: YES\n", line);
        else printf("Case #%d: NO\n", line);
    }
    return 0;
}
