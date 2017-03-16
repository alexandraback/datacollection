#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int A, B, K;
        scanf(" %d %d %d", &A, &B, &K);

        int c = 0;
        for (int a=0; a<A; a++) {
            for (int b=0; b<B; b++) {
                int x = a&b;
                if (x<K) c++;
            }
        }
        printf("%d\n", c);
    }
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
