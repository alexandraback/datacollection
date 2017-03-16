#include <iostream>
using namespace std;

int main() {
    string s;
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        int n;
        scanf("%d", &n);
        int a[1000];
        int maxa = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            if (a[i] > maxa) {
                maxa = a[i];
            }
        }
        int best = 2000;
        for (int d = 1; d <= maxa; d++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (a[i] - 1) / d;
            }
            if (sum + d < best) {
                best = sum + d;
            }
        }
        printf("Case #%d: %d\n", test + 1, best);
    }
    return 0;
}