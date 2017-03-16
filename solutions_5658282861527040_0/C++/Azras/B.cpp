#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        int A, B, K;
        int ans = 0;
        scanf("%d %d %d", &A, &B, &K);
        for (int a = 0; a < A; a++) {
            for (int b = 0; b < B; b++) {
                if ((a & b) < K) {
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}
