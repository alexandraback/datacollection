#include <cstdio>

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        int x, r, c;
        scanf("%d %d %d", &x, &r, &c);

        bool ya = false;
        switch (x) {
            case 1:
                ya = true;
                break;
            case 2:
                ya = (r * c) % 2 == 0;
                break;
            case 3:
                ya = ((r * c) % 3 == 0) && (r >= 2 && c >= 2);
                break;
            case 4:
                ya = ((r * c) % 4 == 0) && (r >= 4 || c >= 4) && (r >= 3 && c >= 3);
                break;
            case 5:
                //TODO
            case 6:
                //TODO
            default:
                ya = false;
        }

        printf("Case #%d: %s\n", t, ya ? "GABRIEL" : "RICHARD");

    }

}
