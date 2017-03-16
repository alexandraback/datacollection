#include <cstdio>
#include <algorithm>
using namespace std;
void solve(int k, int c, int s) {
    if(k > c * s) {
        printf(" IMPOSSIBLE");
        return;
    }
    for(int i = 0; i < k; i += c) {
        unsigned long long ans = 1, pow = 1;
        for(int j = i; j < i + c && j < k; j++, pow *= k)
            ans += pow * j;
        printf(" %llu", ans);
    }
}
int main() {
    unsigned t;
    scanf("%u\n", &t);
    for(unsigned i = 1; i <= t; i++) {
        int k, c, s;
        scanf("%d %d %d", &k, &c, &s);

        printf("Case #%d:", i);
        solve(k, c, s);
        printf("\n");
    }
}

