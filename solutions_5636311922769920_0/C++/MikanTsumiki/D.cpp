#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int cas;
    scanf("%d", &cas);
    for (int _ = 1; _ <= cas; _++) {
        int n, c, s;
        scanf("%d%d%d", &n, &c, &s);
        printf("Case #%d:", _);
        for (int i = 1; i <= n; i++) printf(" %d", i);
        puts("");
    }
}
