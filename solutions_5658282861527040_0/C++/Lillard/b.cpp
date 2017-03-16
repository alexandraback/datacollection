#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int run;
int A, B, K;

void solve() {
    scanf("%d%d%d", &A, &B, &K);
    int res = 0;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            if ((i&j) < K) res++;
        }
    }
    printf("Case #%d: %d\n", run, res);
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (run = 1; run <= test; run++) {
        solve();
    }
    return 0;
}
