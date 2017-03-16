#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
#include <bitset>

using namespace std;

#define ll long long

int N, E, R, V[15], D[15][15], T;

int solve(int n, int e) {
    if(n == N + 1)
        return 0;
    if(D[n][e] != -1)
        return D[n][e];
    int res = 0;
    for(int i = 0;i<=e;i++) {
        res = max(res, solve(n + 1, min(e - i + R, E)) + V[n] * i);
    }
    return D[n][e] = res;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&T);
    for(int c = 1;c<=T;c++) {
        scanf("%d %d %d", &E, &R, &N);
        for(int i = 1;i<=N;i++)
            scanf("%d",&V[i]);
        for(int i = 1;i<=N;i++)
            for(int j = 0;j<=E;j++)
                D[i][j] = -1;
        printf("Case #%d: %d\n", c, solve(1, E));
    }
    return 0;
}
