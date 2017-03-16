#include <cstdio>

using namespace std;

int main() {
    int t, a, b, k;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int ctr = 0;
        scanf("%d%d%d", &a, &b, &k);
        for (int p = 0; p < a; p++) {
            for (int q = 0; q < b; q++) {
                if ((p&q) < k) {
                    ctr++;
                }
            }
        }
        printf("Case #%d: %d\n", i+1, ctr);
    }
    return 0;
}