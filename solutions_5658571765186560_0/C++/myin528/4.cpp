#include <iostream>
using namespace std;

int main() {
    string s;
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        int x, r, c;
        scanf ("%d %d %d", &x, &r, &c);
        if (r > c) {
            int t = r;
            r = c;
            c = t;
        }
        bool result = false;
        if (x == 1) result = true;
        if (x == 2 && r * c % 2 == 0) result = true;
        if (x == 3 && r * c % 3 == 0 && r > 1 && c > 1) result = true;
        if (x == 4 && r * c % 4 == 0 && r > 2 && c > 2) result = true;
        printf("Case #%d: %s\n", test + 1, result ? "GABRIEL" : "RICHARD");
    }
    return 0;
}