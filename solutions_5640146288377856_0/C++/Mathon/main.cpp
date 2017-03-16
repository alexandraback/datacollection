#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        int R, C, W;
        scanf("%d%d%d", &R, &C, &W);
        int col_num = C / W + W;
        if(C % W == 0) col_num--;
        int ans = col_num * R;
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
