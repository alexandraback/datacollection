#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int show[2600];
int main() {
    int cas;
    scanf("%d", &cas);
    for (int _ = 1; _ <= cas; _++) {
        printf("Case #%d:", _);
        scanf("%d", &n);
        memset(show, 0, sizeof show);
        for (int i = 1; i <= n + n - 1; i++) {
            for (int j = 1, v; j <= n; j++) {
                scanf("%d", &v);
                show[v] ^= 1;
            }
        }
        for (int i = 1; i <= 2500; i++) {
            if (show[i]) printf(" %d", i);
        }
        puts("");
    }
}
