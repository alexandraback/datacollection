#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    for(int ti = 0; ti < t; ++ti) {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        int count = 0;
        for(int i = 0; i < a; ++i) {
            for(int j = 0; j < b; ++j) {
                if((i & j) < k) count++;
            }
        }
        printf("Case #%d: %d\n", ti + 1, count);
    }
}
