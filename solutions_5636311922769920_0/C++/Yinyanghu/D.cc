#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int K, C, S;

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++ test) {
        printf("Case #%d:", test);
        scanf("%d %d %d", &K, &C, &S);
        for (int i = 1; i <= K; ++ i)
            printf(" %d", i);
        printf("\n");
    }
    return 0;
}
