#include <cstdio>
#include <algorithm>
using namespace std;

int p[1000];

int need(int d, int l) {
    int x = 0;
    for(int i = 0; i < d; i++)
        x += (p[i] - 1) / l;
    return x;
}

int solve(int d) {
    int best = *max_element(p, p + d);
    for(int i = 1; i < best; i++)
        best = min(best, i + need(d, i));
    return best;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int d;
        scanf("%d", &d);
        for(int j = 0; j < d; j++)
            scanf("%d", p + j);
        printf("Case #%d: %d\n", i, solve(d));
    }
}
