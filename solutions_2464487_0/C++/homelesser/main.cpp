
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long long cas;
    scanf("%lld", &cas);
    for (long long tcas = 1; tcas <= cas; tcas++) {
        long long r, t;
        scanf("%lld%lld", &r, &t);
        long long ans = 0, R = r;
        while (1) {
            long long x = 2 * R + 1;
            if (t >= x) {
                t -= x;
                R += 2;
                ans++;
            } else break;
        }
        printf("Case #%lld: %lld\n", tcas, ans);
    }

    return 0;
}

