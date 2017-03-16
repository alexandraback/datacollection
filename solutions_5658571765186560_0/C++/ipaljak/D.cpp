#include <algorithm>
#include <cstdio>

using namespace std;

int T;

void solve_small(int t) {
    
    printf("Case #%d: ", t);

    int X, R, C;
    scanf("%d%d%d", &X, &R, &C);

    if (R * C % X != 0 || min(R, C) < X - 1) printf("RICHARD\n"); else printf("GABRIEL\n");
}

int main(void) {

    scanf("%d", &T);
    for (int t = 0; t < T; ++t) solve_small(t + 1);

    return 0;

}
