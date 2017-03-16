#include <cstdio>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#define for0(i, n) for(int i = 0; i < n; i++)
using namespace std;
int T, a, n;
int sizes[100];
int INF = 10000000000;
int minStepCount = INF;
int countSteps(int &a, int b){
    if(a == 1){
        return INF;
    }
    int res;
    for(res = 0; a <= b; res++){
        a += a - 1;
    }
    return res;
}
void dfs(int A, int start, int end, int stepCount){
    if(stepCount >= minStepCount){
        return;
    }
    if(start == end){
        minStepCount = stepCount;
        return;
    }
    if(sizes[start] < A){
            dfs(A + sizes[start], start + 1, end, stepCount);
    } else {
        dfs(A, start, start, stepCount + end - start);
        int c = countSteps(A, sizes[start]);
        dfs(A + sizes[start], start + 1, end, stepCount + c);
    }
}
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("assignment.out", "w", stdout);
    scanf("%d", &T);
    for0(i, T){
        scanf("%d %d", &a, &n);
        memset(sizes, 0, sizeof(int) * n);
        for0(j, n){
            scanf("%d", &sizes[j]);
        }
        sort(sizes, sizes + n);
        minStepCount = INF;
        dfs(a, 0, n, 0);
        printf("Case #%d: %d\n", i + 1, minStepCount);
    }
    return 0;
}
