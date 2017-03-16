#include<cstdio>
#include<algorithm>

bool testcase() {
    int N, M;
    scanf("%d %d", &N, &M);
    int a[N][M];
    int maxC[M], maxR[N];
    for(int i = 0; i < N; i ++)
        maxR[i] = 0;
    for(int i = 0; i < M; i ++)
        maxC[i] = 0;

    for(int i = 0; i < N; i ++)
        for(int j = 0; j < M; j ++) {
            scanf("%d", &a[i][j]);
            maxC[j] = std::max(maxC[j], a[i][j]);
            maxR[i] = std::max(maxR[i], a[i][j]);
        }

    for(int i = 0; i < N; i ++)
        for(int j = 0; j < M; j ++)
            if(a[i][j] < maxC[j] && a[i][j] < maxR[i])
                return false;
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i ++) {
        printf("Case #%d: %s\n", i + 1, testcase() ? "YES" : "NO");
    }
}
