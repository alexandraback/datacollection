#include <algorithm>
#include <cstdio>

using namespace std;

int T;

void solve_large(int t) {
    
    printf("Case #%d: ", t);

    int X, R, C;
    scanf("%d%d%d", &X, &R, &C);

    if (X > 6) {
        printf("RICHARD\n");
        return;
    }

    if (R * C % X != 0 || min(R, C) < X - 1) printf("RICHARD\n"); else printf("GABRIEL\n");
}

int main(void) {

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) solve_large(t + 1);

    return 0;

}
