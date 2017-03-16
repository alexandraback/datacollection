#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
int bring, K, L, S;
double hit;
char type[100], key[100], aim[100];

void dfs(int dep) {
    if (dep == S) {
        type[dep] = '\0';
        //printf("%s\n", type);
        int lhit = 0;
        for (int i = 0; i <= S - L; ++i) {
            int flag = 1;
            for (int j = 0; j < L; ++j)
                if (type[i + j] != aim[j])
                    flag = 0;
            lhit += flag;
        }
        bring = max(bring, lhit);
        hit += lhit;
        //printf("%d %.8lf", bring, hit);
        return;
    }
    for (int i = 0; i < K; ++i) {
        type[dep] = key[i];
        dfs(dep + 1);
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d %d %d\n", &K, &L, &S);
        scanf("%s", key);
        scanf("%s", aim);
        //printf("#%s#%s#\n", key, aim);
        bring = 0;
        hit = 0.0;
        dfs(0);
        //printf("%d %.8lf\n", bring, hit);
        double total = 1.0;
        for (int i = 0; i < S; ++i)
            total = total * K;
        hit = bring - hit / total;
        printf("Case #%d: %.8lf\n", Case, hit);
    }
    return 0;
}
