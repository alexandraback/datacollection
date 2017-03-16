#include <cstdio>
#include <cstdlib>

int T, R, C, W;

int main(void) {
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        scanf("%d %d %d", &R, &C, &W);
        int ans = 0;
        ans += C / W * R;
        if (C % W)
            ans += W;
        else
            ans += W - 1;
        printf("Case #%d: %d\n", cases, ans);
    }
    return EXIT_SUCCESS;
}

