#include <cstdio>
#include <iostream>
using namespace std;

void solve(int te) {
    int n, s, p;
    scanf("%d %d %d", &n, &s, &p);
    int ret = 0;
    int lim = p * 3 - 2;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a >= lim) ret++;
        else if (a >= lim - 2 && s > 0 && p > 1) {
            ret++;
            s--;
        }
    }
    printf("Case #%d: %d\n", te, ret);
}

int main() {
    int te;
    scanf("%d", &te);
    for (int i = 1; i <= te; i++) {
        solve(i);
    }
}
