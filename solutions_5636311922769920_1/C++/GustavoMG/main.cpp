#include <cstdio>
#include <cmath>

using namespace std;

int TC, tc, K, C, S;
long long ans, n;

long long binPow(int x, int y) {
    if(y == 0) {
        return 1;
    }
    long long sol = binPow(x, y >> 1);
    if(y & 1) {
        return x * sol * sol;
    }
    return sol * sol;
}

int main() {
    freopen("i.in", "r", stdin);
    freopen("o.out", "w", stdout);
    scanf("%d", &TC);
    while(tc != TC) {
        scanf("%d%d%d", &K, &C, &S);
        if(S < ceil(1.0 * K / C)) {
            printf("Case #%d: IMPOSSIBLE\n", ++tc);
            continue;
        }
        printf("Case #%d:", ++tc);
        n = 0;
        do {
            ans = 0;
            for(int i = C - 1; i >= 0 && n != K; i--) {
                ans += n * binPow(K, i);
                n++;
            }
            printf(" %lld", 1 + ans);
        } while(n != K);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
}
