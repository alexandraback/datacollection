#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

char str[25];
int t, n, dis[1000010], Q[1000010];

int bfs(){
    clr(dis);
    int i, j, k, x, f = 0, l = 0;

    dis[1] = 1;
    Q[l++] = 1;
    while (f < l){
        i = Q[f++];
        if (i == n) return dis[i];

        if ( (i + 1) <= n && !dis[i + 1]){
            dis[i + 1] = dis[i] + 1;
            Q[l++] = i + 1;
        }

        x = 0;
        sprintf(str, "%d", i);
        for (j = strlen(str) - 1; j >= 0; j--) x = (x * 10) + (str[j] - 48);

        if (x <= n && !dis[x]){
            dis[x] = dis[i] + 1;
            Q[l++] = x;
        }
    }
}

int main(){
    read();
    write();
    int T = 0, i, j, counter;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        printf("Case #%d: %d\n", ++T, bfs());
    }
    return 0;
}
