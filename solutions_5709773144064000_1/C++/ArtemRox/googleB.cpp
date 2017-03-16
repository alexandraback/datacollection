#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    double c, f, x, now, ans;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lf %lf %lf", &c, &f, &x);
        ans = 0;
        for (int j = 0; j <= x; j++) {
            now = 2 + j * f;
            if (x / now < c / now + x / (now + f))
                break;
            else
                ans += c / now;
        }
        printf("Case #%d: %.10lf\n", i + 1, ans + x / now);
    }
    return 0;
}
