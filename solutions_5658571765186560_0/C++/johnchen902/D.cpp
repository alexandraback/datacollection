#include <cstdio>
#include <algorithm>
using namespace std;

bool solve(int x, int r, int c) {
    if(r * c % x)
        return true;
    if(x >= 7) {
        // OOO(O...)
        // O O
        // OO
        return true;
    }
    if(x > max(r, c)) {
        // OOO...
        return true;
    }
    if(x > min(r, c) * 2) {
        // OOO...
        // O
        // O
        // ...
        return true;
    }
    if(x == 4 && min(r, c) == 2) {
        //  OO
        // OO
        return true;
    }
    if(x == 5 && min(r, c) == 3 && max(r, c) == 5) {
        //  OO
        // OO
        // O
        return true;
    }
    if(x == 6 && min(r, c) == 3) {
        // OO
        //  OO
        // OO
        return true;
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int x, r, c;
        scanf("%d %d %d", &x, &r, &c);
        printf("Case #%d: %s\n", i, solve(x, r, c) ? "RICHARD" : "GABRIEL");
    }
}
