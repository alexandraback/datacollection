#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000005
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

bool visited[1000010][102];
int t, n, ar[102], dp[1000010][102];

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int F(int c, int i){
    if (i == n || c > MAX) return 0;
    if (visited[c][i]) return dp[c][i];

    int res = 0;
    if (c > ar[i]) res = F(c + ar[i], i + 1);
    else{
        if (c > 1) res = 1 + F((c << 1) - 1, i);
        else res = 1010;
    }
    int x = 1 + F(c, i + 1);
    if (x < res) res = x;

    visited[c][i] = true;
    return (dp[c][i] = res);
}

int main(){
    int line, i, j, a;

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        scanf("%d %d", &a, &n);
        for (i = 0; i < n; i++) scanf("%d", &ar[i]);
        qsort(ar, n, sizeof(int), compare);

        clr(visited);
        int res = F(a, 0);
        printf("Case #%d: %d\n", line, res);
    }
    return 0;
}


