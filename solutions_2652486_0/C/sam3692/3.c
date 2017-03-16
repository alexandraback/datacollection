#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

long long int ar[13];
int primes[] = {2, 3, 5, 7};
bool flag, visited[50][100][100];
int t, r, n, m, k, counter, T[15], R[15];

void backtrack(int i, int B[15], int c, int d){
    if (visited[i][c][d]) return;

    int j;
    if (i > counter && c == T[0] && d == T[1]){
        counter = i;
        for (j = 0; j < counter; j++) R[j] = B[j];
        if (i == n){
            flag = true;
            return;
        }
    }

    if (c < T[0]){
        B[i] = 2;
        backtrack(i + 1, B, c + 1, d);
    }
    if (flag) return;
    if ((c + 1) < T[0]){
        B[i] = 4;
        backtrack(i + 1, B, c + 2, d);
    }
    if (flag) return;
    if ((c + 2) < T[0]){
        B[i] = 8;
        backtrack(i + 1, B, c + 3, d);
    }
    if (flag) return;
    if (d < T[1]){
        B[i] = 3;
        backtrack(i + 1, B, c, d + 1);
    }
    if (flag) return;
    if (c < T[0] && d < T[1]){
        B[i] = 6;
        backtrack(i + 1, B, c + 1, d + 1);
    }

    visited[i][c][d] = true;
}

int main(){
    int line, lol, i, j;

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        scanf("%d %d %d %d", &r, &n, &m, &k);
        printf("Case #%d:\n", line);

        for (lol = 1; lol <= r; lol++){
            counter = 0, flag = false;
            for (i = 0; i < k; i++) scanf("%lld", &ar[i]);

            for (i = 0; i < 4; i++){
                int x = 0;
                for (j = 0; j < k; j++){
                    int c = 0;
                    long long int y = ar[j];
                    while ((y % primes[i]) == 0){
                        y = y / primes[i];
                        c++;
                    }
                    if (c > x) x = c;
                }
                T[i] = x;

                if (i == 0 || i == 1) continue;
                for (j = 0; j < x; j++) R[counter++] = primes[i];
            }

            if (counter != n){
                int B[15];
                for (i = 0; i < counter; i++) B[i] = R[i];

                clr(visited);
                backtrack(counter, B, 0, 0);
            }

            for (i = 0; i < 2; i++){
                if (T[i] != 0){
                     int lim = (n - counter);
                     for (j = 0; j < lim; j++){
                         R[counter++] = primes[i];
                     }
                     break;
                }
            }

            for (i = 0; i < n; i++) printf("%d", R[i]);
            puts("");
        }
    }
    return 0;
}
