#include <stdio.h>

int T;
int x, r, c;

int ans()
{
    if (x == 1) {
        return 1;
    }

    if (x == 2 && (r*c)%2 == 0) {
        return 1;
    }

    if (x == 3 && r != 1 && c == 3) {
        return 1;
    }

    if (x == 4 && r > 2 && c == 4) {
        return 1;
    }

    return 0;
}

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        scanf("%d%d%d", &x, &r, &c);
        if (r > c) {
            int t = r;
            r = c;
            c = t;
        }
        printf("Case #%d: %s\n", z, ans() ? "GABRIEL" : "RICHARD");
    }

	return 0;
}

