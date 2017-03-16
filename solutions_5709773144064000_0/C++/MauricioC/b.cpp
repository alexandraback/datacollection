#include <algorithm>
#include <cstdio>
#include <limits>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        long double C, F, X;
        scanf("%Lf %Lf %Lf", &C, &F, &X);

        long double tme = 0, speed = 2, ans = numeric_limits<long double>::infinity();
        for(int farms = 0; ; farms++) {
            ans = min(ans, tme + X/speed);
            tme += C/speed;
            if(tme + 1e-9 > ans) break;
            speed += F;
        }

        printf("Case #%d: %.8Lf\n", z, ans);
    }
}
