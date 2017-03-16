#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, t, ans, R, C, W, g;
    scanf("%d", &T);
    for(t = 0; t < T; ++t) {
        scanf("%d %d %d", &R, &C, &W);
        g = C / W;
        ans = R * g + W - 1;
        if(C % W != 0) ++ans;
        printf("Case #%d: %d\n", t+1, ans);
    }
}
