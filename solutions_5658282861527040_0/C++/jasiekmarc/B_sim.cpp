#include <cstdio>

int solve() {
    unsigned int a, b, k;
    scanf("%u %u %u", &a, &b, &k);
    int w = 0;
    for(unsigned int x = 0; x < a; x ++)
        for(unsigned int y = 0; y < b; y ++)
            if((x & y) < k)
                w ++;
    return w;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++)
        printf("Case #%d: %d\n", i, solve());
}