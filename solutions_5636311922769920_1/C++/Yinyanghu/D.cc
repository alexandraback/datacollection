#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int K, C, S;

void solve() {
    if (C == 1) {
        if (S == K) {
            for (int i = 1; i <= K; ++ i)
                printf(" %d", i);
        }
        else
            printf(" IMPOSSIBLE");
    }
    else {
        if (K == 1) {
            printf(" 1");
        }
        else if (S >= K - 1) {
            for (int i = 2; i <= K; ++ i)
                printf(" %d", i);
        }
        else
            printf(" IMPOSSIBLE");
    }
    printf("\n");

}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        printf("Case #%d:", test);
        scanf("%d %d %d", &K, &C, &S);
        solve();
    }
    return 0;
}
