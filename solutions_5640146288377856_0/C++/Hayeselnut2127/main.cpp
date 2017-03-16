#include <cstdio>

int T, R, C, W;
int y;

int main () {
    
    scanf("%d", &T);
    
    for (int x = 1; x <= T; x++) {
        scanf("%d %d %d", &R, &C, &W);
        y = R * (C / W) + W;
        if (C % W == 0) y--;
        printf("Case #%d: %d\n", x, y);
    }
    
    return 0;
}